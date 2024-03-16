#include "big_number.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "my_string.h"

BigNumber* CreateBN(char* number_)
{
	if (number_ == NULL || strlen(number_) == 0 ||
		!IsIntString(number_))
		return NULL;

	BigNumber* bn = (BigNumber*)malloc(sizeof(BigNumber));
	if (bn == NULL)
		return NULL;

	size_t size = strlen(number_);
	if (*number_ == '-')
	{
		bn->size = size - 1;
		bn->is_negative = true;
		number_++;
	}
	else
	{
		bn->size = size;
		bn->is_negative = false;
	}

	bn->digits = (digit*)calloc(bn->size, sizeof(digit));
	if (bn->digits == NULL)
	{
		free(bn);
		return NULL;
	}

	for (size_t i = 0; i < bn->size; ++i)
		bn->digits[i] = number_[i] - '0';

	return bn;
}

void DeleteBN(BigNumber** bn_)
{
	free((*bn_)->digits);
	free(*bn_);

	*bn_ = NULL;
}

void PrintBN(BigNumber* bn_)
{
	if (bn_ == NULL)
	{
		printf("BigNumber is empty!\n");
		return;
	}

	if (bn_->is_negative)
		printf("-");

	for (size_t i = 0; i < bn_->size; ++i)
		printf("%u", bn_->digits[i]);

	printf("\n");
}

BigNumber* SumBN(BigNumber* bn1_, BigNumber* bn2_)
{
	BigNumber* result = malloc(sizeof(BigNumber));
	if (result == NULL)
		return NULL;

	result->size = max(bn1_->size, bn2_->size) + 1;
	result->digits = (digit*)calloc(result->size, sizeof(digit));

	if (result->digits == NULL)
	{
		free(result);
		return NULL;
	}

	if (bn1_->is_negative ==true && bn2_->is_negative==false)
	{
		bn1_->is_negative = false;
		//SUB(bn_1, bn_2)
		bn1_->is_negative = true;
	}
	else if (bn1_->is_negative == false && bn2_->is_negative == true)
	{
		bn2_->is_negative = false;
		//SUB(bn_1, bn_2)
		bn2_->is_negative = true;
	}
	else
	{
		result->is_negative = false;

		BigNumber* min_bn = bn1_->size <= bn2_->size ? bn1_ : bn2_;
		BigNumber* max_bn = bn1_->size > bn2_->size ? bn1_ : bn2_;

		int carry = 0;
		int diff = max_bn->size - min_bn->size;

		for (int i = min_bn->size - 1; i >= 0; --i)
		{
			char sum = (min_bn->digits[i] + max_bn->digits[i + diff]) + carry;
			result->digits[i + diff] = sum % 10;

			carry = sum / 10;
		}

		for (int i = diff - 1; i >= 0; --i)
		{
			char sum = max_bn->digits[diff] + carry;
			result->digits[diff] = sum % 10;
			carry = sum / 10;
		}

		result->digits[0] = carry;

		return result;
	}
}



