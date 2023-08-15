// Fill out your copyright notice in the Description page of Project Settings.


#include "Medpack.h"

AMedpack::AMedpack()
{
	ItemData.ItemClass = this->StaticClass();
	HealthValue = 10.0f;
}

void AMedpack::UseItem(ASWGMainCharacter* Character)
{
	Super::UseItem(Character);
	if (Character)
	{
		Character->addHealth(HealthValue);
	}
}
