#include "SDLCombo.h"


SDLComboOption::SDLComboOption(
	SDLCombo* pp, 
	string po,
	string pv,
	bool pd)
{
	parent = pp;
	option = po;
	value = pv;
	selected = pd;
	
	durum = NORMAL;
	tip = COMBOOPTION;
	
	yazi = new SDLLabel(option);
	if (yazi->getWidth() > parent->getWidth())
		w = yazi->getWidth() + 6;
	else w = parent->getWidth() + 6; // spacing
	h = 20;
}

SDLCombo::SDLCombo()
{
	tip = SDLWidget::COMBO;
	durum = CLOSED;
	SDLCombo *me = this;
	button = new SDLButton("img/combo.png", "v");
	button->clicked = makeFunctor((CBFunctor0*)0, *me, &SDLCombo::toggleOptions);
	yazi = 0;
	w = 0;
	h = button->getHeight();
}

/**
 * Adds an SDLComboOption to the SDLCombo. If the size of the 
 * SDLComboOption is larger, then all the widgets are set up
 * accordingly. All the other SDLComboOptions grow to the new size,
 * SDLButton and SDLLabel are also repositioned.
 */
void SDLCombo::addOption(string option, string value, bool def)
{
	SDLComboOption temp(this, option, value, def);
	
	if (temp.getWidth() > w)
	{
		w = temp.getWidth();
		px2 = px1 + w; // update for the new width
	}
	
	for (int i=0;i<options.size();i++)
		options[i].setWidth(w);
	
	temp.setPosition(px1, (py2 + 1) + (temp.getHeight()*options.size()));
	if (def)
	{
		yazi = new SDLLabel(option);
		yazi->setPosition(px1+4, py1 + ((h - yazi->getHeight())/2));
	}
	
	button->setPosition(px2, py1);
	options.push_back(temp);
}

/**
 * Toggles options, this is executed via the SDLButton
 */
void SDLCombo::toggleOptions()
{
	if (durum == OPEN)
		hideOptions();
	else if (durum == CLOSED)
		showOptions();
}

string SDLCombo::getSelected()
{
	for(int i=0;i<options.size();i++)
	{
		if (options[i].isSelected())
			return options[i].getValue();
	}
}

void SDLCombo::handleEvent(int eventType, int button, int x, int y)
{
	this->button->handleMouseEvent(eventType, button, x, y);
	if (durum == CLOSED) 
	{
		switch(eventType)
		{
			case SDL_MOUSEBUTTONDOWN:
				if (button == SDL_BUTTON_LEFT && isMouseOver(x, y))
				{
					toggleOptions();
					return;
				}
		}
	}
	else if (durum == OPEN)
	{
		for (int i=0;i<options.size();i++)
		{
			switch(eventType)
			{
				case SDL_MOUSEMOTION:
					if (options[i].isMouseOver(x, y))
						options[i].setState(SDLComboOption::OVER);
					else options[i].setState(SDLComboOption::NORMAL);
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (button == SDL_BUTTON_LEFT)
					{
						if (isMouseOver(x, y))
						{
							toggleOptions();
						}
						if(options[i].isMouseOver(x, y))
						{
							for (int j=0;j<options.size();j++)
								options[j].deSelect();
							options[i].setSelected();
							delete(yazi);
							yazi = new SDLLabel(options[i].getOption());
							toggleOptions();
							return;
						}
					}
					break;
			}
		}
	}
}

