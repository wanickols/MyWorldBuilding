// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable/InteractableBase.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//Functions
//This is a base class so besides debugging this won't be used.
void AInteractableBase::OnInteract_Implementation(AActor* Caller)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("Interacted"));
}

void AInteractableBase::StartFocus_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("StartFocus"));
}

void AInteractableBase::EndFocus_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("EndFocus"));
}

