// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "items/Item_2.h"
#include "Weapons.generated.h"

class USoundBase;
class UBoxComponent;

UCLASS()
class SLASH_API AWeapons : public AItem_2
{
	GENERATED_BODY()

public:
	AWeapons();
	void Equip(USceneComponent* InParent, FName InSocketName);
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);

protected:

	virtual void BeginPlay() override;

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	USoundBase* EquipSound;

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	UBoxComponent* Weaponbox;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

public:

	FORCEINLINE UBoxComponent* GetWeaponBox() const { return Weaponbox;}

};


