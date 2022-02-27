// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerVolume.h"
#include "MoveDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FUTURAESCAPE_API UMoveDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void MoveDoor(float DeltaTime);
	float TotalMassOfActor() const;
		
private:
	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere);
	float TargetYaw = 90.f;

	UPROPERTY(EditAnywhere);
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere);
	AActor* ActorThatOpens;

	UPROPERTY(EditAnywhere);
	float DoorOpenSpeed = 0.5f;

	UPROPERTY(EditAnywhere);
	float MassRequireToOpenDoor = 50.f;
};
