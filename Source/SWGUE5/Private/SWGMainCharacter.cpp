// Fill out your copyright notice in the Description page of Project Settings.


#include "SWGMainCharacter.h"


// Sets default values
ASWGMainCharacter::ASWGMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASWGMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	// This is a test
}

void ASWGMainCharacter::Server_Interact_Implementation(FVector Start, FVector End)
{
	this->Interact(Start, End);
}

bool ASWGMainCharacter::Server_Interact_Validate(FVector Start, FVector End)
{
	return true;
}

void ASWGMainCharacter::Server_UseItem_Implementation(TSubclassOf<AItem> ItemSubclass)
{
	this->UseItem(ItemSubclass);
}

bool ASWGMainCharacter::Server_UseItem_Validate(TSubclassOf<AItem> ItemSubclass)
{
	for (FItemData& Item : InventoryItems)
	{
		if (Item.ItemClass == ItemSubclass)
		{
			return true;
		}
	}

	return false;
}

void ASWGMainCharacter::onReplicateInventoryItems()
{
	if (!InventoryItems.IsEmpty())
	{
		AddItemandUpdateInventortyWidgetTest(InventoryItems.Last(), InventoryItems);
	}
}

void ASWGMainCharacter::Interact(FVector Start, FVector End)
{
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	DrawDebugLine(GetWorld(), Start, End, FColor(255, 0, 0), true);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
	{
		if (IInteractableInterface* Interface = Cast<IInteractableInterface>(HitResult.GetActor()))
		{
			Interface->Interact(this);
		}
	}
}

void ASWGMainCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ASWGMainCharacter, InventoryItems, COND_OwnerOnly);
	DOREPLIFETIME(ASWGMainCharacter, mPlayerHealth);
	DOREPLIFETIME(ASWGMainCharacter, mPlayerHunger);
}

// Called every frame
void ASWGMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASWGMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASWGMainCharacter::addHealth(float HealthAdded)
{
	mPlayerHealth += HealthAdded;
	if(IsLocallyControlled())
		UpdateStats(mPlayerHunger, mPlayerHealth);
	UE_LOG(LogTemp, Warning, TEXT("Added Health: %f"), HealthAdded);
}

void ASWGMainCharacter::removeHungry(float value)
{
	mPlayerHunger -= value;
	if (IsLocallyControlled())
		UpdateStats(mPlayerHunger, mPlayerHealth);
	UE_LOG(LogTemp, Warning, TEXT("Removed Hungry: %f"), value);
}

void ASWGMainCharacter::UseItem(TSubclassOf<AItem> ItemSubclass)
{
	if (ItemSubclass)
	{
		if (HasAuthority())
		{
			if (AItem* CDOItem = ItemSubclass.GetDefaultObject())
			{
  				CDOItem->UseItem(this);
				
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed CDO"));
			}
		}
		else
		{
			if (AItem* CDOItem = ItemSubclass.GetDefaultObject())
			{
				CDOItem->UseItem(this);
			}
			Server_UseItem(ItemSubclass);
		}

		for (FItemData& Item : InventoryItems)
		{
			if (Item.ItemClass == ItemSubclass)
			{
				Item.stackCount--;
				break;
			}
		}
		if (IsLocallyControlled())
		{
			onReplicateInventoryItems();
		}
	}
}

void ASWGMainCharacter::InteractBP()
{
	
}

void ASWGMainCharacter::onRep_Stats()
{
	if (IsLocallyControlled())
	{
		UpdateStats(mPlayerHunger, mPlayerHealth);
	}
}

void ASWGMainCharacter::AddInventoryItem(FItemData item)
 {
	 if (HasAuthority())
	 {
		 bool isNewItem = true;
		 for (FItemData& ItemLoop : InventoryItems)
		 {
			 if (ItemLoop.ItemClass == item.ItemClass)
			 {
				 ItemLoop.stackCount++;
				 isNewItem = false;
				 break;
			 }
		 }

		 if (isNewItem)
		 {
			 InventoryItems.Add(item);
			 
		 }
		 if (IsLocallyControlled())
		 {
			 onReplicateInventoryItems();
		 }
	 }
 }

void ASWGMainCharacter::UpdateStats_Implementation(float NewHunger, float NewHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("Updating the stats"));
}

