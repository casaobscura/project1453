#include "UOKoylu.h"

SDL_Surface* Koylu::spriteImg = 0;

Koylu::Koylu()
{
	cost.set(0, 400, 0); 
	addReq("Temel Teknoloji");
	faction = "Osmanlı";
	sndSelected = 0;
	sndConfirmed = 0;
	yuru = dur = evbtn = resim = 0;
}

Koylu::Koylu(SDL_Surface *scr, Player *p):BaseUnit(scr, p, "Köylü")
{
	cost.set(0, 400, 0); 
	addReq("Temel Teknoloji");
	faction = "Osmanlı";
	
	// temel bileşenler
	hitpoints = 20;
	buildRate = 1000; 
	armor = 2;
	damage = 10;
	range = 1;
	sight = 4;
	speed = 10;
	morale = 60;
	xp = 10;
	kills = 0;
	
	// grafiksel bileşenler
	hotspot.x = hotspot.y = 18;
	hotspot.w = hotspot.h = 32;
	cx = cy = 32; 
	
	selected = false;
	
	SDL_Rect t;
	t.w = t.h = 64;
	
	if (spriteImg == 0)
	{
		spriteImg = loadImg("graphics/units/osmanli/koylu.png");
	}
	
	for(int i=0;i<8;i++)
	{
		sprites[i].setImg(spriteImg);
		sprites[i].addState("dur");
		sprites[i].addState("yuru");
		
		t.x = i*64;
		t.y = 0;
		sprites[i].addFrameToState("dur", t, 1000);
		
		for (int j=0;j<2;j++)
		{
			t.x = i*64;
			t.y = 64 + (j*64);
			sprites[i].addFrameToState("yuru", t, 100);
		}
	}
	
	yon = S;
	setState("dur");
	healthBar = new SDLProgressBar(32, 4, GREEN, 0, hitpoints);
	
	// sesler
	sndSelected = new SDLMixer("wavs/ottoman/koylu01.ogg");
	sndConfirmed = new SDLMixer("wavs/ottoman/koylu02.ogg");
	
	// alt ekran: komutlar
	SDL_Rect trect;
	trect.x = trect.y = 0;
	trect.w = trect.h = 32;
	
	Koylu *me = this;
	
	yuru = new SDLCommandButton(screen, trect, "Yürü");
	yuru->setPosition(665,295);
	yuru->dugme->clicked = makeFunctor((CBFunctor0*)0, *me, &Koylu::setCommandYuru);
	komutlar->addWidget(yuru);
	
	trect.x = 32; trect.y = 0;
	dur = new SDLCommandButton(screen, trect, "Dur");
	dur->setPosition(705,295);
	dur->dugme->clicked = makeFunctor((CBFunctor0*)0, *me, &Koylu::actionDur);
	komutlar->addWidget(dur);
	
	trect.x = 64; trect.y = 0;
	evbtn = new SDLCommandButton(screen, trect, "Ev Yap", Ev().getCost());
	evbtn->setPosition(745, 295);
	komutlar->addWidget(evbtn);
	
	trect.x = 128; trect.y = 0;
	resim = new SDLCommandButton(screen, trect, "Köylü");
	resim->setPosition(655, 205);
	komutlar->addWidget(resim);
	
	sbar = new SDLProgressBar(90, 14, GREEN, 0, hitpoints);
	sbar->setPosition(695, 223);
	komutlar->addWidget(sbar);
}

Koylu::~Koylu()
{
	delete sndSelected;
	delete sndConfirmed;
}

void Koylu::setCommandCalis()
{
	setState("calis");
}

