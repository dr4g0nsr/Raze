//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2020 - Christoph Oelckers

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
aint with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
Modifications for JonoF's port by Jonathon Fowler (jf@jonof.id.au)
*/
//------------------------------------------------------------------------- 

#include "ns.h"	// Must come before everything else!

#include "duke3d.h"
#include "demo.h"
#include "screens.h"
#include "baselayer.h"
#include "m_argv.h"
#include "mapinfo.h"
#include "texturemanager.h"

BEGIN_DUKE_NS

static inline int movefifoend(int myconnectindex)
{
#if 1
	return g_player[myconnectindex].movefifoend;
#else
	return movefifoend[myconnectindex];
#endif
}

static void fakedomovethings()
{
	// prediction
}

static void fakedomovethingscorrect()
{
	// unprediction
}

/*
void mploadsave()
{
    for(int i=connecthead;i>=0;i=connectpoint2[i])
        if( sync[i].bits&(1<<17) )
    {
        multiflag = 2;
        multiwhat = (sync[i].bits>>18)&1;
        multipos = (unsigned) (sync[i].bits>>19)&15;
        multiwho = i;

        if( multiwhat )
        {
            saveplayer( multipos );
            multiflag = 0;

            if(multiwho != myconnectindex)
            {
                strcpy(&fta_quotes[122],&ud.user_name[multiwho][0]);
                strcat(&fta_quotes[122]," SAVED A MULTIPLAYER GAME");
                FTA(122,&ps[myconnectindex]);
            }
            else
            {
                strcpy(&fta_quotes[122],"MULTIPLAYER GAME SAVED");
                FTA(122,&ps[myconnectindex]);
            }
            break;
        }
        else
        {
//            waitforeverybody();

            j = loadplayer( multipos );

            multiflag = 0;

            if(j == 0 && !RR)
            {
                if(multiwho != myconnectindex)
                {
                    strcpy(&fta_quotes[122],&ud.user_name[multiwho][0]);
                    strcat(&fta_quotes[122]," LOADED A MULTIPLAYER GAME");
                    FTA(122,&ps[myconnectindex]);
                }
                else
                {
                    strcpy(&fta_quotes[122],"MULTIPLAYER GAME LOADED");
                    FTA(122,&ps[myconnectindex]);
                }
                return 1;
            }
        }
    }
}
*/

//---------------------------------------------------------------------------
//
// 
//
//---------------------------------------------------------------------------
int domovethings();

char moveloop()
{
    int i;

    if (numplayers > 1)
        while (fakemovefifoplc < movefifoend[myconnectindex]) fakedomovethings();

    getpackets();

    if (numplayers < 2) bufferjitter = 0;
    while (movefifoend(myconnectindex)-movefifoplc > bufferjitter)
    {
        for(i=connecthead;i>=0;i=connectpoint2[i])
            if (movefifoplc == movefifoend(i)) break;
        if (i >= 0) break;
        if( domovethings() ) return 1;
    }
    return 0;
}

//---------------------------------------------------------------------------
//
// 
//
//---------------------------------------------------------------------------

int domovethings()
{
    int i, j;
    int ch;

	// mplpadsave();

    ud.camerasprite = -1;
    lockclock += TICSPERFRAME;

    if(earthquaketime > 0) earthquaketime--;
    if(rtsplaying > 0) rtsplaying--;

    if( show_shareware > 0 )
    {
        show_shareware--;
        if(show_shareware == 0)
        {
            pus = NUMPAGES;
            pub = NUMPAGES;
        }
    }

    everyothertime++;

    for(i=connecthead;i>=0;i=connectpoint2[i])
        copybufbyte(&inputfifo[movefifoplc&(MOVEFIFOSIZ-1)][i],&sync[i],sizeof(input));
    movefifoplc++;

    updateinterpolations();

    j = -1;
    for(i=connecthead;i>=0;i=connectpoint2[i])
     {
          if ((sync[i].bits&(1<<26)) == 0) { j = i; continue; }

          if (i == myconnectindex) gameexit(" ");
          if (screenpeek == i)
          {
                screenpeek = connectpoint2[i];
                if (screenpeek < 0) screenpeek = connecthead;
          }

          if (i == connecthead) connecthead = connectpoint2[connecthead];
          else connectpoint2[j] = connectpoint2[i];

          numplayers--;
          ud.multimode--;

          closedemowrite();

          if (numplayers < 2 && !RR)
              sound(GENERIC_AMBIENCE17);

          pub = NUMPAGES;
          pus = NUMPAGES;
          vscrn();

          Printf(PRINT_NOTIFY, "%s is history!",ud.user_name[i]);

          quickkill(&ps[i]);
          deletesprite(ps[i].i);

          if(j < 0 && networkmode == 0 )
              gameexit( " \nThe 'MASTER/First player' just quit the game.  All\nplayers are returned from the game. This only happens in 5-8\nplayer mode as a different network scheme is used.");
      }

      if ((numplayers >= 2) && ((movefifoplc&7) == 7))
      {
            ch = (char)(randomseed&255);
            for(i=connecthead;i>=0;i=connectpoint2[i])
                 ch += ((ps[i].posx+ps[i].posy+ps[i].posz+ps[i].ang+ps[i].horiz)&255);
            syncval[myconnectindex][syncvalhead[myconnectindex]&(MOVEFIFOSIZ-1)] = ch;
            syncvalhead[myconnectindex]++;
      }

    if(ud.recstat == 1) record();

    if( ud.pause_on == 0 )
    {
        global_random = TRAND;
        movedummyplayers();//ST 13
    }

    for(i=connecthead;i>=0;i=connectpoint2[i])
    {
        cheatkeys(i);

        if( ud.pause_on == 0 )
        {
            processinput(i);
            checksectors(i);
        }
    }

    if( ud.pause_on == 0 )
    {
		fi.think();
    }

    fakedomovethingscorrect();

    if( (everyothertime&1) == 0)
    {
        animatewalls();
        movecyclers();
        pan3dsound();
    }


    return 0;
}


END_DUKE_NS

