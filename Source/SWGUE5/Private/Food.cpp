// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"

void AFood::UseItem(ASWGMainCharacter* Character)
{
	Super::UseItem(Character);
	if (Character)
	{
		Character->removeHungry(HungryValue);
	}
}
