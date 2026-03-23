// AssignmentActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssignmentActor.generated.h"

UCLASS()
class HW05_API AAssignmentActor : public AActor
{
	GENERATED_BODY()

public:
    AAssignmentActor();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    void PrintLocation();

    void Move(float Distance);

    void Turn(float Degrees, float DeltaZ);

    void RandomMoveTurn();
};