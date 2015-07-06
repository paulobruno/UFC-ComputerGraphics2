#include "Scene.h"


Scene::Scene()
{
    backgroundColor = ColorRgba(0.0f, 0.0f, 0.0f);
    width = 640;
    height = 480;
    camera = Camera();
    loader = SceneXmlLoader();
    perspective = Perspective();
}


Scene::~Scene()
{
    while (!lights.empty())
    {
        lights.pop_back();
    }
    lights.clear();

    while (!objects.empty())
    {
        objects.pop_back();
    }
    objects.clear();
}


void Scene::loadXml(const char* filename)
{
    loader.loadXml(filename);


    width = loader.getWidth();
    height = loader.getHeight();
    camera = loader.getCamera();
    perspective = loader.getPerspective();

    lights = loader.getLights();
    objects = loader.getObjects();
}


void Scene::saveXml(const char* filename)
{
    loader.saveXml(filename);
}
