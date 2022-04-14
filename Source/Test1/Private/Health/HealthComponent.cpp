// Fill out your copyright notice in the Description page of Project Settings.


#include "Health/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent() : maxHealth(100), currHealth(maxHealth)
{
	//We want health to be reactive, not constantly updating
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	//Gets owner of component
	AActor* owner = GetOwner();
	if (owner)
	{
		//Overrides ontakeanydamage function of owner to our takedamage in this class. 
		owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
	
}


//At the moment this just takes damage until 0, but values such as defense or others could be easily added here.
void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
		return;

	currHealth = FMath::Clamp(currHealth - Damage, 0.0f, maxHealth);//clamps it to not go under 0 or over maxHealth

}

