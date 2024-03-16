#include <stdbool.h>

typedef unsigned char digit;

// ��� �������� ����� (>10 ������)
typedef struct BigNumber
{
	unsigned int size;		// ������ �����
	digit* digits;  	// ������ �� ���� �����
	bool is_negative;	// ���� �����
} BigNumber;

/*
* @brief �������� �������� �����
* @param number_ : ������ � ������� ������
* @return ��������� �� ���������� ������ � ������� ������
*/
BigNumber* CreateBN(char* number_);

/*
* @brief ������� ��������� ������� �����
* @param bn_ : ��������� �� ������� �����
*/
void DeleteBN(BigNumber** bn_);

/*
* @brief ������ �������� �����
* @param bn_ : ��������� �� ������� �����
*/
void PrintBN(BigNumber* bn_);

/*
* @brief ����� ���� ������� �����
* @param bn1_, bn2_ : ������� �����
* @return ������� ����� �� ����� ���� �������
*/
BigNumber* SumBN(BigNumber* bn1_, BigNumber* bn2_);
