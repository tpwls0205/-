//1. Fruit ������Ʈ��
//seller.saleApple(buyer, 2000);
//ó�� ȣ���� �� �ֵ��� �����ϼ���

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