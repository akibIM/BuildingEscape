// Copyright Akib Mehedi 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActor() const;
	void FindAudioComponent();
	void FindPressurePlate();

	bool OpenDoorSound;
	bool CloseDoorSound;

private:	

	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
		float OpenAngle = 90.f;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;

	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 1.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseSpeed = 2.5f;

	UPROPERTY(EditAnywhere)
		float MassToOpenDoor = 50.f;
	
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	/*UPROPERTY(EditAnywhere)
		AActor* ActorThatOpen = nullptr;*/
	
	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;
};
