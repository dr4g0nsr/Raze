#pragma once

#include "screenjob.h"
#include "constants.h"
#include "packet.h"
#include "types.h"

struct MapRecord;

BEGIN_DUKE_NS



// dumping ground for all external function prototypes to keep them out of the important headers.
// This list is not sorted in any way.

void lava_cleararrays();
void addjaildoor(int p1, int p2, int iht, int jlt, int p3, int h);
void addminecart(int p1, int p2, int i, int iht, int p3, int childsectnum);
void addtorch(int i);
void addlightning(int i);

void movecyclers(void);
void movedummyplayers(void);
void resetlanepics(void);
void moveplayers();
void doanimations();
void movefx();
void moveclouds(double smoothratio);

void RANDOMSCRAP(DDukeActor* i);
void ms(DDukeActor* i);
void movecrane(DDukeActor* i, int crane);
void movefountain(DDukeActor* i, int fountain);
void moveflammable(DDukeActor* i, int tire, int box, int pool);
void detonate(DDukeActor* i, int explosion);
void movemasterswitch(DDukeActor* i, int spectype1, int spectype2);
void movetrash(DDukeActor* i);
void movewaterdrip(DDukeActor* i, int drip);
void movedoorshock(DDukeActor* i);
void movetouchplate(DDukeActor* i, int plate);
void movecanwithsomething(DDukeActor* i);
void bounce(DDukeActor* i);
void movetongue(DDukeActor* i, int tongue, int jaw);
void rpgexplode(DDukeActor* i, int j, const vec3_t& pos, int EXPLOSION2, int EXPLOSIONBOT2, int newextra, int playsound);
void moveooz(DDukeActor* i, int seenine, int seeninedead, int ooz, int explosion);
void lotsofstuff(DDukeActor* s, int n, int spawntype);
bool respawnmarker(DDukeActor* i, int yellow, int green);
bool rat(DDukeActor* i, bool makesound);
bool queball(DDukeActor* i, int pocket, int queball, int stripeball);
void forcesphere(DDukeActor* i, int forcesphere);
void recon(DDukeActor* i, int explosion, int firelaser, int attacksnd, int painsnd, int roamsnd, int shift, int (*getspawn)(DDukeActor* i));
void ooz(DDukeActor* i);
void reactor(DDukeActor* i, int REACTOR, int REACTOR2, int REACTORBURNT, int REACTOR2BURNT, int REACTORSPARK, int REACTOR2SPARK);
void camera(DDukeActor* i);
void forcesphereexplode(DDukeActor* i);
void watersplash2(DDukeActor* i);
void frameeffect1(DDukeActor* i);
bool money(DDukeActor* i, int BLOODPOOL);
bool jibs(DDukeActor* i, int JIBS6, bool timeout, bool callsetsprite, bool floorcheck, bool zcheck1, bool zcheck2);
bool bloodpool(DDukeActor* i, bool puke, int TIRE);
void shell(DDukeActor* i, bool morecheck);
void glasspieces(DDukeActor* i);
void scrap(DDukeActor* i, int SCRAP1, int SCRAP6);

void handle_se00(DDukeActor* i, int LASERLINE);
void handle_se01(DDukeActor* i);
void handle_se14(DDukeActor* i, bool checkstat, int RPG, int JIBS6);
void handle_se30(DDukeActor* i, int JIBS6);
void handle_se02(DDukeActor* i);
void handle_se03(DDukeActor* i);
void handle_se04(DDukeActor* i);
void handle_se05(DDukeActor* i, int FIRELASER);
void handle_se08(DDukeActor* i, bool checkhitag1);
void handle_se10(DDukeActor* i, const int *);
void handle_se11(DDukeActor* i);
void handle_se12(DDukeActor* i, int planeonly = 0);
void handle_se13(DDukeActor* i);
void handle_se15(DDukeActor* i);
void handle_se16(DDukeActor* i, int REACTOR, int REACTOR2);
void handle_se17(DDukeActor* i);
void handle_se18(DDukeActor* i, bool morecheck);
void handle_se19(DDukeActor* i, int BIGFORCE);
void handle_se20(DDukeActor* i);
void handle_se21(DDukeActor* i);
void handle_se22(DDukeActor* i);
void handle_se24(DDukeActor* actor, int16_t* list1, int16_t* list2, int TRIPBOMB, int LASERLINE, int CRANE, int shift);
void handle_se25(DDukeActor* a, int t_index, int snd1, int snd2);
void handle_se26(DDukeActor* i);
void handle_se27(DDukeActor* i);
void handle_se31(DDukeActor* a, bool choosedir);
void handle_se32(DDukeActor* i);
void handle_se35(DDukeActor* i, int SMALLSMOKE, int EXPLOSION2);
void handle_se128(DDukeActor* i);
void handle_se130(DDukeActor* i, int countmax, int EXPLOSION2);

void respawn_rrra(DDukeActor* oldact, DDukeActor* newact);

int dodge(DDukeActor*);
void alterang(int ang, DDukeActor* actor, int g_p);
void fall_common(int g_i, int g_p, int JIBS6, int DRONE, int BLOODPOOL, int SHOTSPARK1, int squished, int thud, int(*fallspecial)(int, int), void (*falladjustz)(spritetype*));
void checkavailweapon(struct player_struct* p);
void deletesprite(DDukeActor* num);
void addammo(int weapon, struct player_struct* p, int amount);

int ssp(DDukeActor* i, unsigned int cliptype); //The set sprite function
void insertspriteq(DDukeActor *i);
int wakeup(int sn, int pn);


int timedexit(int snum);
void dokneeattack(int snum, int pi, const std::initializer_list<int>& respawnlist);
int endoflevel(int snum);
void playerisdead(int snum, int psectlotag, int fz, int cz);
void footprints(int snum);
int makepainsounds(int snum, int type);
void playerCrouch(int snum);
void playerJump(int snum, int fz, int cz);
void processavel(player_struct* p, float* avel); 
void checklook(int snum, ESyncBits actions);
void playerCenterView(int snum);
void playerLookUp(int snum, ESyncBits actions);
void playerLookDown(int snum, ESyncBits actions);
void playerAimUp(int snum, ESyncBits actions);
void playerAimDown(int snum, ESyncBits actions);
bool view(struct player_struct* pp, int* vx, int* vy, int* vz, short* vsectnum, int ang, fixed_t q16horiz, double smoothratio);
void tracers(int x1, int y1, int z1, int x2, int y2, int z2, int n);
int hits(int i);
int hitasprite(int i, short* hitsp);
int aim(spritetype* s, int aang);
void checkweapons(struct player_struct* const p);
int findotherplayer(int p, int* d);
void quickkill(struct player_struct* p);
void setpal(struct player_struct* p);
int madenoise(int playerNum);
int haskey(int sect, int snum);
void shootbloodsplat(int i, int p, int sx, int sy, int sz, int sa, int atwith, int BIGFORCE, int OOZFILTER, int NEWBEAST);

void breakwall(short newpn, short spr, short dawallnum);
void callsound2(int soundNum, int playerNum);
int callsound(int sectnum,int snum);
int hitasprite(int snum,short *hitSprite);
int findplayer(const spritetype* s, int* dist);
void operatejaildoors(int hitag);
void allignwarpelevators(void);
bool isablockdoor(int tileNum);
bool activatewarpelevators(int s, int w);
int check_activator_motion(int lotag);
void operateactivators(int l, int w);
void operateforcefields_common(int s, int low, const std::initializer_list<int>& tiles);
void operatemasterswitches(int lotag);
void operatesectors(int s, int i);
void hud_input(int playerNum);
int getanimationgoal(int animtype, int animindex);
bool isanearoperator(int lotag);
bool isanunderoperator(int lotag);
int setanimation(short animsect, int animtype, int animindex, int thegoal, int thevel);
void dofurniture(int wallNum, int sectnum, int playerNum);
void dotorch();
int hitawall(struct player_struct* pl, int* hitWall);
int hits(int snum);

void   clearsectinterpolate(int sprnum);
void   setsectinterpolate(int sprnum);
DDukeActor* LocateTheLocator(int n, int sectnum);
void clearcamera(player_struct* ps);

void showtwoscreens(const CompletionFunc& func);
void doorders(const CompletionFunc& func);

void LoadActor(int i, int p, int x);
void execute(int s, int p, int d);
void makeitfall(DDukeActor* s);
int furthestangle(DDukeActor* snum, int angDiv);
void getglobalz(DDukeActor* s);
void OnEvent(int id, int pnum = -1, int snum = -1, int dist = -1);

short EGS(short whatsect, int s_x, int s_y, int s_z, short s_pn, signed char s_s, signed char s_xr, signed char s_yr, short s_a, short s_ve, int s_zv, short s_ow, signed char s_ss);
void ceilingglass(int snum, int sectnum, int cnt);
void spriteglass(int snum, int cnt);
void lotsofcolourglass(int snum, int wallNum, int cnt);
void lotsofglass(int snum, int wallnum, int cnt);

void addspritetodelete(int spnum);
void checkavailinven(struct player_struct* p);
int initspriteforspawn(int j, int pn, const std::initializer_list<int> &excludes);
void spawninitdefault(int j, int i);
void spawntransporter(int j, int i, bool beam);
int spawnbloodpoolpart1(int j, int i);
void initfootprint(int j, int i);
void initshell(int j, int i, bool isshell);
void initcrane(int j, int i, int CRANEPOLE);
void initwaterdrip(int j, int i);
int initreactor(int j, int i, bool isrecon);
void spawneffector(int i);
void gameexitfrommenu();
int startrts(int lumpNum, int localPlayer);

void pickrandomspot(int pn);
void resetinventory(int pn);
void resetplayerstats(int pn);
void resetweapons(int pn);
void resetprestat(int snum, int g);
void prelevel_common(int g);
void cacheit_d();
void cacheit_r();

void FTA(int q, struct player_struct* p);
void OnMotorcycle(player_struct *pl, int snum);
void OffMotorcycle(player_struct *pl);
void OnBoat(player_struct *pl, int snum);
void OffBoat(player_struct *pl);

void cameratext(int i);
void dobonus(int bonusonly, const CompletionFunc& completion);
void dobonus_d(int bonusonly, const CompletionFunc& completion);
void dobonus_r(int bonusonly, const CompletionFunc& completion);

void drawoverlays(double smoothratio);
void drawbackground(void);
void displayrooms(int32_t playerNum, double smoothratio);
void setgamepalette(int palid);
void resetmys();
void resettimevars();
bool setnextmap(bool checksecretexit);
void prelevel_d(int g);
void prelevel_r(int g);
void e4intro(const CompletionFunc& completion);
void exitlevel(MapRecord *next);
void enterlevel(MapRecord* mi, int gm);
void donewgame(MapRecord* map, int sk);
void startnewgame(MapRecord* map, int skill);
void setlocalplayerinput(player_struct *pp);
int playercolor2lookup(int color);
void PlayerColorChanged(void);
void apply_seasick(player_struct* p, double scalefactor);
void calcviewpitch(player_struct* p, double factor);
bool movementBlocked(int snum);
void loadcons();
void recordoldspritepos();

void updateinterpolations();
void restoreinterpolations();
void setinterpolation(int* posptr);
void stopinterpolation(int* posptr);
void dointerpolations(int smoothratio);
int* animateptr(int i);

void backuppos(player_struct* p, bool noclipping = false);
void backupweapon(player_struct* p);
void checkhardlanding(player_struct* p);
void playerweaponsway(player_struct* p, spritetype* s);

END_DUKE_NS
