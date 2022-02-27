// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FUTURAESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere);
	float RaycastLength = 100.f;

	UInputComponent* InputComponent = nullptr;

	void Grab();
	void Release();
	void SetupInputComponent();
	void FindPhysicsHandle();

	FHitResult GetFirstPhysicsBodyInRange() const;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	FVector GetPlayersReach() const;
	FVector GetPlayersWorldPos() const;
};
