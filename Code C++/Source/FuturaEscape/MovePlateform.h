// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerVolume.h"
#include "MovePlateform.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FUTURAESCAPE_API UMovePlateform : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovePlateform();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	float TotalMassOfActors() const;
	void DisableActor();
	UPROPERTY(EditAnywhere, Category = "Disable");
	bool HideInGame;

private:

	UPROPERTY(EditAnywhere);
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere);
	AActor* ActorThatOpens;

	UPROPERTY(EditAnywhere);
	float MassRequireToOpenDoor = 30.f;

	
};
