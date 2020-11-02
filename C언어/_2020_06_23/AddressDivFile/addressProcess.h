#pragma once

// 함수의 선언부(원형)

// View 부분 / 눈에 보이는 부분
void showMenu();
int getSelMenu();

// Controller 부분(Service/Business) / 처리 부분
void insertAddress();
void printAllAddress();
int processAddress(int sel);

// Model 부분 / 데이터 부분
//void saveAllAddress();
//void loadAllAddress();