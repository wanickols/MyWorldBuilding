// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable/TouchInteractableBase.h"
#include <Components/BoxComponent.h>
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"


ATouchInteractableBase::ATouchInteractableBase()
{
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	boxComp->InitBoxExtent(FVector(150, 100, 100));
	boxComp->SetCollisionProfileName("Trigger");
	//boxComp->SetupAttachment(RootComponent);
	RootComponent = boxComp; 
}

void ATouchInteractableBase::BeginPlay()
{
	Super::BeginPlay();

	//Sets onOverlap of boxComp to call my own function
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ATouchInteractableBase::OnOverlapBegin);

}

//Calls onInteract function, no logic
void ATouchInteractableBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor != this)
	{

		ATP_ThirdPersonCharacter* OtherCharacter = Cast<ATP_ThirdPersonCharacter>(OtherActor);

		if (OtherCharacter)
		{
			this->OnInteract(OtherCharacter);
		}
	}
}
//This is a base class so this will only be used for debugging
void ATouchInteractableBase::OnInteract_Implementation(AActor* Caller)
{

	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("Interacted"));
}
