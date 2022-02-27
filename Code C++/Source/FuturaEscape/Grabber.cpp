// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	SetupInputComponent();
	FindPhysicsHandle();
	// ...
	
}

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component found on %s "), *GetOwner()->GetName());
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Release", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component not found on %s "), *GetOwner()->GetName());
	}
}
void UGrabber::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Component physics handle not found on %s"), *GetOwner()->GetName());
	}
}
void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabber press"));
	FHitResult HitActor = GetFirstPhysicsBodyInRange();
	UPrimitiveComponent* ComponentToGrab = HitActor.GetComponent();

	if (HitActor.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Item Grabbed : %s"), *HitActor.GetActor()->GetName());
		PhysicsHandle->GrabComponentAtLocationWithRotation
		(
			ComponentToGrab,
			NAME_None,
			GetPlayersReach(),
			HitActor.GetActor()->GetActorRotation()
		);
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabber release"));
	PhysicsHandle->ReleaseComponent();
}
FHitResult UGrabber::GetFirstPhysicsBodyInRange()const
{


	FHitResult HitActor;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		HitActor,
		GetPlayersWorldPos(),
		GetPlayersReach(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	//Recupérer l'actor touché par le raycast
	AActor* ActorHit = HitActor.GetActor();

	if (ActorHit)
	{
		UE_LOG(LogTemp, Error, TEXT("Raycast hit : %s"), *(ActorHit->GetName()));
	}

	return (HitActor);
	DrawDebugLine(
		GetWorld(),
		GetPlayersReach(),
		GetPlayersWorldPos(),
		FColor(0, 255, 0),
		false,
		0.f,
		0,
		7.5f);
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetPlayersReach());
	}
	// ...
}




FVector UGrabber::GetPlayersWorldPos() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
	return (PlayerViewPointLocation);
}

FVector UGrabber::GetPlayersReach() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
	return (PlayerViewPointLocation + PlayerViewPointRotation.Vector() *RaycastLength);
}