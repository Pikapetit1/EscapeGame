// Fill out your copyright notice in the Description page of Project Settings.


#include "EnableActor.h"

// Sets default values for this component's properties
UEnableActor::UEnableActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnableActor::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no pressureplate set!"), *GetOwner()->GetName());
	}
	
		DisableActor();
	

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UEnableActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TotalMassOfActors() >= MassRequireToOpenDoor)
	{
			EnableActor();
	}
	// ...
}

void UEnableActor::EnableActor()
{
	GetOwner()->SetActorHiddenInGame(false);

	GetOwner()->SetActorEnableCollision(true);

	GetOwner()->SetActorTickEnabled(true);
}

void UEnableActor::DisableActor()
{
	GetOwner()->SetActorHiddenInGame(true);

	GetOwner()->SetActorEnableCollision(false);

	GetOwner()->SetActorTickEnabled(false);
}

float UEnableActor::TotalMassOfActors() const
{
	float TotalMass = 0.f;

	//find all overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		TotalMass = TotalMass + Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return (TotalMass);
}