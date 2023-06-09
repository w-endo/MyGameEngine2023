#include "Childoden.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"

Childoden::Childoden(GameObject* parent)
	:GameObject(parent, "ChildOden"),hModel_(-1)
{
}

Childoden::~Childoden()
{
}

void Childoden::Initialize()
{
    hModel_ = Model::Load("Assets/oden.fbx");
    assert(hModel_ >= 0);//モデル番号が-1のままだったらあさーとに引っかかる

    transform_.scale_.x = 0.2f;
    transform_.scale_.y = 0.2f;
    transform_.scale_.z = 0.2f;
    //transform_.position_.x = 2.0f;
    //transform_.position_.y = 1.0f;
}

void Childoden::Update()
{
    transform_.rotate_.y++;
    transform_.position_.z += 0.5f;
    if (transform_.position_.z > 50)
    {
        KillMe();
    }
}

void Childoden::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Childoden::Release()
{

}
