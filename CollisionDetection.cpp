//
// Created by belisariops on 7/20/16.
//

#include "CollisionDetection.h"
#include "BVH.h"

CollisionDetection ::CollisionDetection(std::vector<Actor *> actors) {
    this->actors = actors;
}

void CollisionDetection ::addActor(Actor *actor) {
    this->actors.push_back(actor);
}

void CollisionDetection ::popActor(Actor *actor) {

}

void CollisionDetection ::tick() {
    std::vector<BVH*>clusters;
  for (auto actor: actors)
      clusters.push_back(new BVH(actor));

    while (clusters.size()>1){
        int best = 10000000000;
        BVH* left;
        BVH* right;
        for (auto c1 : clusters){
            for (auto c2 : clusters){
                if (c1 != c2 && c1->distance(c2)<best){
                    best = c1->distance(c2);
                    left = c1;
                    right = c2;

                }
            }
        }
        for (auto rec : clusters)
           if
        BVH* c = new BVH(left,right);

    }
}
