// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerVolume.h"
#include "Opendoor.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FUTURAESCAPE_API UOpendoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpendoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;

private:

	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.f;
	

	UPROPERTY(EditAnywhere);
	float TargetYaw = -180.0f;

	UPROPERTY(EditAnywhere);
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere);
	AActor* ActorThatOpens;

	UPROPERTY(EditAnywhere);
	float DoorOpenSpeed = 0.5f;

	UPROPERTY(EditAnywhere);
	float DoorCloseSpeed = 0.1f;

	UPROPERTY(EditAnywhere);
	float DoorCloseDelay = 0.5f;

	UPROPERTY(EditAnywhere);
	float MassRequireToOpenDoor = 50.f;
};