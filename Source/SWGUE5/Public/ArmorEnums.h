// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "ArmorEnums.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API UArmorEnums : public UUserDefinedEnum
{
	GENERATED_BODY()
	
};

UENUM(BlueprintType)
enum class UArmorTypeEnum : uint8
{
	ARMOR_TYPE_NONE = 0x00, // This means that the item is not armor
	ARMOR_TYPE_LIGHT,
	ARMOR_TYPE_MEDIUM,
	ARMOR_TYPE_HEAVY,
	ArmorTypeEnum_Max UMETA(Hidden)
};
