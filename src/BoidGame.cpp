// #include <BoidGame.hpp>

// #include <Vector2.hpp>
// #include <Boid.hpp>
// #include <Random.hpp>

// void BoidGame::Init(int windowWidth, int windowHeight, sf::Texture *texture)
// {
//     this->windowWidth = windowWidth;
//     this->windowHeight = windowHeight;
//     this->texture = texture;
// }

// BoidGame::BoidGame() { Init(800, 600, nullptr); }

// BoidGame::BoidGame(int windowWidth, int windowHeight, sf::Texture *texture) { Init(windowWidth, windowHeight, texture); }

// void BoidGame::Start()
// {
//     int numBoids = 50;

//     // Create numBoids boids
//     for (int i = 0; i < numBoids; i++)
//     {
//         Boid boid;
//         // boid.position = Vector2(Random::Range(0.0f, (float)windowWidth), Random::Range(0.0f, (float)windowHeight));
//         // boid.velocity = Vector2(Random::Range(-1.0f, 1.0f), Random::Range(-1.0f, 1.0f));
//         // boid.sprite.setTexture(*texture);
//         boids.push_back(boid);
//     }
// }

// std::vector<GameObject> BoidGame::Update()
// {
//     std::vector<GameObject> gameObjects;

//     // Update boids
//     for (Boid &boid : boids)
//     {
//         boid.Update();
//         // gameObjects.push_back(boid);
//     }

//     return gameObjects;
// }