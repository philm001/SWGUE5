// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWGMainCharacter.h"
#include "StaticItem.h"
#include "Item.h"
#include "Food.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API AFood : public AStaticItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
		float HungryValue;

public:
	AFood()
	{
		ItemData.ItemClass = this->StaticClass();
		HungryValue = 40.0;
	}

	virtual void UseItem(ASWGMainCharacter* Character) override;
	
};
