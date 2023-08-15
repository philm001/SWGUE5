// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWGMainCharacter.h"
#include "StaticItem.h"
#include "Medpack.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API AMedpack : public AStaticItem
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
		float HealthValue;


public:
	AMedpack();

	virtual void UseItem(ASWGMainCharacter* Character) override;
	
};
