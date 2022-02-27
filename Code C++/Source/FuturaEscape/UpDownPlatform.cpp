// Fill out your copyright notice in the Description page of Project Settings.


#include "UpDownPlatform.h"

// Sets default values for this component's properties
UUpDownPlatform::UUpDownPlatform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	direction = 1;

	// ...
}


// Called when the game starts
void UUpDownPlatform::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUpDownPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector NewLocation = GetOwner()->GetActorLocation();


	if (NewLocation.Z > 900)
	{
		direction = direction * -1;
	}

	if (NewLocation.Z < 600)
	{
		direction = direction * -1;
	}

	NewLocation.Z += direction * 2.f;
	GetOwner()->SetActorLocation(NewLocation);
	// ...
}

