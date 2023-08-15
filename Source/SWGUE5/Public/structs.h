#pragma once


#include "CoreMinimal.h"
#include "WeaponEnums.h"
#include "ArmorEnums.h"
#include <TextureResource.h>
#include "structs.generated.h"


// Created in different view
/* This is the main struct for any item. It is all inclusive*/
USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class AItem> ItemClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int32 ItemCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FString InternalName;// The internal data name that the item will use

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FString DataTableName; // The name if the datatable that the item is stored in

	// Data related to weapons
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UWeaponDamageTypeEnum ItemDamageType = UWeaponDamageTypeEnum::DAMAGE_TYPE_NONE;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UWeaponTypeEnum ItemWeaponType = UWeaponTypeEnum::WEAPON_TYPE_NONE;

	// Data related to Armor items
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UArmorTypeEnum ArmorType = UArmorTypeEnum::ARMOR_TYPE_NONE;

	UPROPERTY(BlueprintReadWrite)
		int32 stackCount = 1 ;

};



//UENUM(BlueprintType)