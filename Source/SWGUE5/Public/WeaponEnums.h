// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "WeaponEnums.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API UWeaponEnums : public UUserDefinedEnum
{
	GENERATED_BODY()
	
};

UENUM(BlueprintType)
enum class UWeaponDamageTypeEnum : uint8
{
	DAMAGE_TYPE_NONE = 0x00,
	DAMAGE_TYPE_KINETIC,
	DAMAGE_TYPE_ENERGY,
	DAMAGE_TYPE_BLAST,
	DAMAGE_TYPE_STUN,
	DAMAGE_TYPE_RESTRAINT,
	DAMAGE_TYPE_ELEMENTAL_HEAT,
	DAMAGE_TYPE_ELEMENTAL_COLD,
	DAMAGE_TYPE_ELEMENTAL_ACID,
	DAMAGE_TYPE_ELEMENTAL_ELECTRIC,
	DAMAGE_TYPE_ENVIRONMENTAL_HEAT,
	DAMAGE_TYPE_ENVIRONMENTAL_COLD,
	DAMAGE_TYPE_ENVIRONMENTAL_ACID,
	DAMAGE_TYPE_ENVIRONMENTAL_ELECTRIC,
	WeaponDamageTypeEnum_Max UMETA(Hidden)
};


UENUM(BlueprintType)
enum class UWeaponTypeEnum : uint8
{
	WEAPON_TYPE_NONE = 0x00, // default state for all items. This means that the item is not a weapon
	WEAPON_TYPE_LIGHT_RIFLE,
	WEAPON_TYPE_PISTOL,
	WEAPON_TYPE_HEAVY_WEAPON,
	WEAPON_TYPE_SINGLE_HANDED_WEAPON,
	WEAPON_TYPE_DOUBLE_HANDED_WEAPON,
	WEAPON_TYPE_UNARMED,
	WEAPON_TYPE_POLEARM,
	WEAPON_TYPE_THROWN,
	WEAPON_TYPE_SINGLE_HANDED_LIGHTSABER,
	WEAPON_TYPE_DOUBLE_HANDED_LIGHTSABER,
	WEAPON_TYPE_POLEARM_LIGHTSABER, // This one is interesting...
	WEAPON_TYPE_GROUND_TARGETTING,
	WEAPON_TYPE_DIRECTION_TARGETTING,
	WeaponTypeEnum_Max UMETA(Hidden)
};
