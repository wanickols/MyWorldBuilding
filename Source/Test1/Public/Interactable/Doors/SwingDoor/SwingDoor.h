// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable/InteractableBase.h"
#include "SwingDoor.generated.h"

/**
 * 
 */
UCLASS()
class TEST1_API ASwingDoor : public AInteractableBase
{
	GENERATED_BODY()
public:

	//Constructor
	ASwingDoor();

	//Tick
	virtual void Tick(float DeltaTime) override;

	//Interface Functions
	void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller) override;

	void StartFocus();
	virtual void StartFocus_Implementation();

	void EndFocus();
	virtual void EndFocus_Implementation();

private:

	//Meshes
	UPROPERTY(EditAnywhere, Category = Meshes)
		UStaticMeshComponent* doorMesh;

	UPROPERTY(EditAnywhere, Category = Meshes)
		UStaticMeshComponent* doorFrameMesh;

	//Door Functions
	UFUNCTION()
		void OpenDoor(AActor* Caller);

	UFUNCTION()
		void CloseDoor(AActor* Caller);


	//Variables
	bool isOpen;

	UPROPERTY(EditAnywhere, Category = Interactable)
		float maxDegree;
	
	UPROPERTY(EditAnywhere, Category = Interactable)
		float doorSpeed;
	
	float RotateValue;
	FRotator doorRotation;
};
