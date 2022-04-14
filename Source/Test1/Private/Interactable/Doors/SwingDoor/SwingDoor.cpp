// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable/Doors/SwingDoor/SwingDoor.h"
#include <Kismet/KismetMathLibrary.h>

ASwingDoor::ASwingDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	doorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	RootComponent = doorFrameMesh;

	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	doorMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	doorMesh->SetupAttachment(RootComponent);

	doorMesh->SetRelativeLocation(FVector(0.0f, 50.0f, 0));
	doorMesh->SetRelativeScale3D(FVector(1.f, 1.1f, 1.0f));
	isOpen = false;
	maxDegree = 90.f;
	doorSpeed = .01f;
}

void ASwingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Updates door rotation
	doorRotation = doorMesh->GetRelativeRotation();

	if (isOpen) //Opens door towards rotateValue
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Opening"));
		doorMesh->SetRelativeRotation(FMath::Lerp(FQuat(doorRotation), FQuat(FRotator(0.0f, RotateValue, 0.0f)), doorSpeed));
	}
	else //closes door towards orignal positon
	{
		doorMesh->SetRelativeRotation(FMath::Lerp(FQuat(doorRotation), FQuat(FRotator(0.0f, 0.0f, 0.0f)), doorSpeed*2));
	}
}


//####Interface Functions####
void ASwingDoor::OnInteract_Implementation(AActor* Caller)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("Called"));
	//Opens or closes door based on whether it's open
	if (isOpen)
		CloseDoor(Caller);
	else
		OpenDoor(Caller);
}

//Gonna be used in blueprints for widget
void ASwingDoor::StartFocus_Implementation()
{
}

void ASwingDoor::EndFocus_Implementation()
{
}

//####Functions####

//Open Door
void ASwingDoor::OpenDoor(AActor* Caller)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("Opened"));
	if (Caller != nullptr && Caller != this)
	{
		FVector PawnLocation = Caller->GetActorLocation();
		FVector Direction = GetActorLocation() - PawnLocation;
		Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());

		if (Direction.X > 0.0f)
		{
			RotateValue = maxDegree;
		}
		else
		{
			RotateValue = -maxDegree;
		}
		doorMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		isOpen = true;
	}
}


//Close Door
void ASwingDoor::CloseDoor(AActor* Caller)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, TEXT("Closed"));
	if (Caller != nullptr && Caller != this)
	{
		doorMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		isOpen = false;
	}
}
