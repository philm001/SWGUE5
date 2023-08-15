// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../StaticItem.h"
#include "../WeaponEnums.h"
#include "WeaponObject.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API AWeaponObject : public AStaticItem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		UWeaponDamageTypeEnum GetWeaponDamageType() { return ItemData.ItemDamageType; }

	UFUNCTION(BlueprintCallable)
		UWeaponTypeEnum	GetWeaponType() { return ItemData.ItemWeaponType; }
};
