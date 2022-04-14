// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable/InteractableBase.h"
#include "TouchInteractableBase.generated.h"

/**
 * 
 */
UCLASS()
class TEST1_API ATouchInteractableBase : public AInteractableBase
{
	GENERATED_BODY()
public:

	//Constructor
	ATouchInteractableBase();

	virtual void BeginPlay() override;

protected:
	//Box Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounds")
		class UBoxComponent* boxComp;

	//Functions
	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnInteract_Implementation(AActor* Caller);
};
