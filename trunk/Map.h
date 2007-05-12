#ifndef MAP__H__
#define MAP__H__

#include <iostream>
#include "Headers.h"
#include "Player.h"
#define TILESIZE 32
#define ACC 4 
#define TOL 10

using namespace std;

class Player;

class MapTile
{
	public:
	enum tileType {
		CIM,
		SARICIM,
		TOPRAK,
		AGAC,
		AGACKESIK,
		DAGLIK,
		DENIZ
	};
	
	MapTile();
	void setType(tileType t, bool obs);
	void draw(SDL_Rect src, SDL_Rect dest);
	tileType getTip();
	bool isExplored();
	bool tileKontrol(tileType t);
	void setExplored();
	bool isObstructed();
	SDL_Rect s, d; // nereleri cizilmis tutuyor bunlar :)
	
	static SDL_Surface* screen;
	
	private:
	bool obstruction;
	bool unexplored;
	tileType tip;
	static SDL_Surface *tileList;
};


class Map
{
	public:
	Map(SDL_Surface *scr, int w, int h);
	void setOrigin(int x, int y);
	void setCurrentX(int x);
	void setCurrentY(int y);
	void setCurrent(int x, int y);
	int getCx();
	int getCy();
	void setPane(int w, int h);
	void update();
	void drawMiniMap();
	void setMiniMapPos(int x, int y);
	void draw(bool running);
	void handleEvents(SDL_Event *event);
	int getPx();
	int getPy();
	int getCpux();
	int getCpuy();
	void setPlayers(Player* h, Player* c);
	
	// playerdan gelenler
	bool multipleSelect;
	int rsx1, rsx2, rsy1, rsy2;
	bool isMultipleSelecting();
	bool isValidSelection();
	
	void exploreTiles(int tx, int ty, int range);
	void startBuildSel(int size, MapTile::tileType type);
	void endBuildSel();
	bool uygun();
	bool tileEmpty(int ex, int ey);
	
	private:
	Player *human, *cpu;
	bool drawing, dragging;
	int buildsize;
	MapTile::tileType buildtype;
	MapTile** tiles;
	SDL_Surface* screen;
	int ox, oy; // ekrandaki posizyon, sol üst
	int cx, cy; // current x & y
	int pw, ph; // ekrandaki genişlik / yükseklik
	int sx, sy; // step x - step y 
	int xb, xs; // xbaşla - xson 
	int yb, ys; // ybaşla - yson
	int tx, ty; // tile count
	int rw, rh; // real width tx*TILESIZE
	int vx, vy; // velocity 
	int ax, ay; // acceleration 
	int mtx, mty; // mouse hangi tile üzerinde :D 
	int mmx, mmy; // mini map positions
	// starting points for player and computer
	int startpx, startpy, startcx, startcy;
	bool scroll; // kare secim sirasinda scroll'u engellemek için
};





#endif

