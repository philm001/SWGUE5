// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "SWGMainCharacter.h"


// Sets default values
AItem::AItem()
{
	bReplicates = true;

 	

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}



void AItem::DuplicateItem()
{
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	SpawnParams.Template = this;
	if (GetWorld())
	{
		GetWorld()->SpawnActor<AItem>(this->GetClass(), FVector(0, 0, -20000), FRotator(), SpawnParams);
	}
}

void AItem::Interact(ASWGMainCharacter* Character)
{
	if (HasAuthority() && Character)
	{
		b_IsInsideInventory = true;
		Character->AddInventoryItem(ItemData);
		this->Destroy();
	}
}

void AItem::UseItem(ASWGMainCharacter* Character)
{

}


