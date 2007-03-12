#include "Cost.h"

Cost::Cost()
{
}

Cost::Cost(Wood wc, Food fc, Stone sc)
{
	WoodCost = wc;
	FoodCost = fc;
	StoneCost = sc;
}

Cost::Cost(int wc, int fc, int sc)
{
	WoodCost = Wood(wc);
	FoodCost = Food(fc);
	StoneCost = Stone(sc);
}

bool Cost::compare(Wood wc, Food fc, Stone sc)
{
	return ( (WoodCost.getAmount() <= wc.getAmount()) && (FoodCost.getAmount() <= fc.getAmount()) && (StoneCost.getAmount() <= sc.getAmount()) );
}
