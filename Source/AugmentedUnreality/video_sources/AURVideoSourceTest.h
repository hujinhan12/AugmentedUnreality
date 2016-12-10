/*
Copyright 2016 Krzysztof Lis

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "AURVideoSource.h"
#include "AURVideoSourceTest.generated.h"

/**
 * Test video source, shows frames filled with random colors;
 */
UCLASS(Blueprintable, BlueprintType)
class UAURVideoSourceTest : public UAURVideoSource
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VideoSource)
	FIntPoint DesiredResolution;

	UPROPERTY(EditAnywhere, Category = VideoSource, meta = (ClampMin = "0.5", ClampMax = "60.0", UIMin = "0.5", UIMax = "60.0"))
	float FramesPerSecond;

	UAURVideoSourceTest();

	virtual bool Connect() override;
	virtual bool IsConnected() const override;
	virtual void Disconnect() override;
	virtual bool GetNextFrame(cv::Mat & frame) override;
	virtual FIntPoint GetResolution() const override;
	virtual float GetFrequency() const override;
};
	