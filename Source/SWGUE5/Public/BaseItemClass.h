// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItemClass.generated.h"

/**
 * 
 */
UCLASS()
class SWGUE5_API UBaseItemClass : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Variables")
		int32 TestVariable;


	UBaseItemClass();
	~UBaseItemClass();
};
