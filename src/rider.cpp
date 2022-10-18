#include "rider.hpp"

using namespace std;
using namespace csX75;

Human::Human()
{
    // Creating the torso
    Cuboid cuboid(7, 10, 3, glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
    torso = new HNode(NULL, cuboid.num_vertices, cuboid.vert_arr, cuboid.col_arr, cuboid.num_vertices*sizeof(glm::vec4), cuboid.num_vertices*sizeof(glm::vec4));

    // Creating the limbs
    Cylinder limb(6, 1, 10, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));   

    left_arm[0] = new HNode(torso, limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    left_arm[0]->change_parameters(5, 2.0, 0.0, 90.0, 0.0, 0.0);

    left_arm[1] = new HNode(left_arm[0], limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    left_arm[1]->change_parameters(0.0, 0.0, 6.0, 0.0, 0.0, 0.0);

    right_arm[0] = new HNode(torso, limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    right_arm[0]->change_parameters(-5.0, 2.0, 0.0, 90.0, 0.0, 0.0);

    right_arm[1] = new HNode(right_arm[0], limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    right_arm[1]->change_parameters(0.0, 0.0, 6.0, 0.0, 0.0, 0.0);

    left_leg[0] = new HNode(torso, limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    left_leg[0]->change_parameters(2, -8.0, 0.0, 90.0, 0.0, 0.0);

    left_leg[1] = new HNode(left_leg[0], limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    left_leg[1]->change_parameters(0.0, 0.0, 6.0, 0.0, 0.0, 0.0);

    right_leg[0] = new HNode(torso, limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    right_leg[0]->change_parameters(-2.0, -8.0, 0.0, 90.0, 0.0, 0.0);

    right_leg[1] = new HNode(right_leg[0], limb.num_vertices, limb.vert_arr, limb.col_arr, limb.num_vertices*sizeof(glm::vec4), limb.num_vertices*sizeof(glm::vec4));
    right_leg[1]->change_parameters(0.0, 0.0, 6.0, 0.0, 0.0, 0.0);

    // Creating the neck
    Cylinder gardan(1, 1.5, 10, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
    neck = new HNode(torso, gardan.num_vertices, gardan.vert_arr, gardan.col_arr, gardan.num_vertices*sizeof(glm::vec4), gardan.num_vertices*sizeof(glm::vec4));
    neck->change_parameters(0.0, 5.5, 0.0, 90.0, 0.0, 0.0);

    // Creating the face
    Sphere sphere(2, 10, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    head = new HNode(neck, sphere.num_vertices, sphere.vert_arr, sphere.col_arr, sphere.num_vertices*sizeof(glm::vec4), sphere.num_vertices*sizeof(glm::vec4));
    head->change_parameters(0.0, 0.0, -2.5, 0.0, 0.0, 0.0);
}
Human::~Human() {
    delete this->left_arm[0], this->left_arm[1];
    delete this->left_leg[0], this->left_leg[1];
    delete this->right_arm[0], this->right_arm[1];
    delete this->right_leg[0], this->right_leg[1];
    delete this->torso, this->neck, this->head;
}