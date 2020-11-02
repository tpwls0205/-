//1. Fruit 프로젝트를
//seller.saleApple(buyer, 2000);
//처럼 호출할 수 있도록 수정하세요

#include "FruitBuyer.h"
#include "FruitSeller.h"

void main()
{
	FruitSeller seller;
	FruitBuyer buyer;
	seller.saleApple(buyer, 2000);

	seller.showSaleResult();
	buyer.showBuyResult();
}