#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

#include "fensterchen.hpp"

TEST_CASE("Test_1 Sphere","[Default Constructor]")
{
  std::cout<<"-----------------"<<std::endl;	
	Sphere s1{};

	REQUIRE(s1.getcenter().x == 0);
	REQUIRE(s1.getcenter().y == 0);
	REQUIRE(s1.getcenter().z == 0);

	REQUIRE(s1.getradius() == 1);
}

TEST_CASE("Test_2 sphere","[User Constructor 1]")
{
  std::cout<<"-----------------"<<std::endl;
	Sphere s2{glm::vec3(1,1,1),5};

	REQUIRE(s2.getcenter().x == 1);
	REQUIRE(s2.getcenter().y == 1);
	REQUIRE(s2.getcenter().z == 1);

	REQUIRE(s2.getradius() == 5);	
}

TEST_CASE("Test_3 sphere","[User Constructor 2]")
{
  std::cout<<"-----------------"<<std::endl;
  Material m1{};
  Sphere s3{glm::vec3(1,1,1),5, m1,"Sphere Test 3"};

  REQUIRE(s3.getcenter().x == 1);
  REQUIRE(s3.getcenter().y == 1);
  REQUIRE(s3.getcenter().z == 1);

  REQUIRE(s3.getradius() == 5); 
}

TEST_CASE("Test_4 sphere", "[area]")
{  
  std::cout<<"-----------------"<<std::endl;
  Sphere s4{glm::vec3(1,1,1),5};

  REQUIRE( Approx(s4.area()) == 314.159 );
}

TEST_CASE("Test_5 sphere", "[volume]")
{  
  std::cout<<"-----------------"<<std::endl;
  Sphere s5{glm::vec3(1,1,1),5};

  REQUIRE( Approx(s5.volume()) == 523.6 );
}

//box

TEST_CASE("Test_1 box", "[default ctor]")
{  
  std::cout<<"-----------------"<<std::endl;
  Box b1{};

  REQUIRE( b1.getmin().x == 0.0);
  REQUIRE( b1.getmin().y == 0.0);
  REQUIRE( b1.getmin().z == 0.0);
  
  REQUIRE( b1.getmax().x == 0.0);
  REQUIRE( b1.getmax().y == 0.0);
  REQUIRE( b1.getmax().z == 0.0);
}

TEST_CASE("Test_2 box", "[user Constructor 1]")
{
  std::cout<<"-----------------"<<std::endl;
  Box b2{ glm::vec3(1,1,1), glm::vec3(2,2,2) };

  REQUIRE( b2.getmin().x == 1.0);
  REQUIRE( b2.getmin().y == 1.0);
  REQUIRE( b2.getmin().z == 1.0);
  
  REQUIRE( b2.getmax().x == 2.0);
  REQUIRE( b2.getmax().y == 2.0);
  REQUIRE( b2.getmax().z == 2.0);
}

TEST_CASE("Test_3 box", "[user Constructor 2]")
{
  std::cout<<"-----------------"<<std::endl;
  Material m2{};
  Box b2{ glm::vec3(1,1,1), glm::vec3(2,2,2), m2, "Box Test_3" };

  REQUIRE( b2.getmin().x == 1.0);
  REQUIRE( b2.getmin().y == 1.0);
  REQUIRE( b2.getmin().z == 1.0);
  
  REQUIRE( b2.getmax().x == 2.0);
  REQUIRE( b2.getmax().y == 2.0);
  REQUIRE( b2.getmax().z == 2.0);
}


TEST_CASE("Test_4 box", "[area]")
{
  std::cout<<"-----------------"<<std::endl;
  Box b4{ glm::vec3(1,1,1), glm::vec3(2,2,2) };

  REQUIRE( b4.getmin().x == 1.0);
  REQUIRE( b4.getmin().y == 1.0);
  REQUIRE( b4.getmin().z == 1.0);
  
  REQUIRE( b4.getmax().x == 2.0);
  REQUIRE( b4.getmax().y == 2.0);
  REQUIRE( b4.getmax().z == 2.0);
  REQUIRE( Approx(b4.area()) == 6 );
}

TEST_CASE("Test_5 box", "[volume]")
{
  std::cout<<"-----------------"<<std::endl;
  Box b5{ glm::vec3(1,1,1), glm::vec3(2,2,2) };

  REQUIRE( b5.getmin().x == 1.0);
  REQUIRE( b5.getmin().y == 1.0);
  REQUIRE( b5.getmin().z == 1.0);
  
  REQUIRE( b5.getmax().x == 2.0);
  REQUIRE( b5.getmax().y == 2.0);
  REQUIRE( b5.getmax().z == 2.0);
  REQUIRE( Approx(b5.volume()) == 1 );
}


//shape - color & name

TEST_CASE("Test_1 Shape default", "[Material Color Test for ka,kd and ks]")
{
  std::cout<<"-----------------"<<std::endl;
  Box b1{};

  b1.print(std::cout);

  REQUIRE( b1.getmaterial().getKA().r == 1);
  REQUIRE( b1.getmaterial().getKA().g == 1);
  REQUIRE( b1.getmaterial().getKA().b == 1);

  REQUIRE( b1.getmaterial().getKD().r == 1);
  REQUIRE( b1.getmaterial().getKD().g == 1);
  REQUIRE( b1.getmaterial().getKD().b == 1);

  REQUIRE( b1.getmaterial().getKS().r == 1);
  REQUIRE( b1.getmaterial().getKS().g == 1);
  REQUIRE( b1.getmaterial().getKS().b == 1);  
}

TEST_CASE("Test_2 Shape default", "[name]")
{
  std::cout<<"-----------------"<<std::endl;
  Sphere s1{};

  s1.print(std::cout);
  
  REQUIRE( s1.getname() == "default Shape" );
}


TEST_CASE("Test_3 Shape User", "[name]")
{
  std::cout<<"-----------------"<<std::endl;
  Material m3{};
  Sphere s1{glm::vec3(1,1,1),5, m3,"Sphere Name Test"};

  s1.print(std::cout);
  
  REQUIRE( s1.getname() == "Sphere Name Test" );
}

TEST_CASE("intersectRaySphere", "[intersect]")
{

  std::cout<<"-----------------"<<std::endl;
  // Ray
  glm::vec3 ray_origin(0.0,0.0,0.0);
  // ray direction has to be normalized ! // you can use:
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction(0.0,0.0,1.0);
  // Sphere
  glm::vec3 sphere_center(0.0,0.0,5.0);

  float sphere_radius (1.0);
  float distance (0.0);

  auto result = glm::intersectRaySphere( ray_origin , ray_direction , sphere_center , sphere_radius , distance );

  REQUIRE(distance == Approx(4.0f)); 
}

TEST_CASE("Test Sphere intersect", "[intersect]")
{
  auto s = std::make_shared<Sphere> (glm::vec3{0.0,0.0,5.0},1.0, Material{}, "Test_Sphere");
  Ray r(glm::vec3{0.0,0.0,0.0},glm::vec3{0.0,0.0,1.0});

  float t = 0.0;
  auto intersection = s -> intersect(r,t);

  REQUIRE(intersection.first == true);
  REQUIRE(intersection.second == 4.0);

}
/*
TEST_CASE("Test Destructor", "[6.8]")
{
  std::cout<<"-------S0----------"<<std::endl;
  Color red(255, 0, 0); 
  glm::vec3 position(0,0,0);
  Sphere* s0 = new Sphere(position, 1.2, red, "sphere0");
  std::cout<<"--------S1---------"<<std::endl; 
  Shape* s1 = new Sphere(position, 1.2, red, "sphere1");
  std::cout<<"-----------------"<<std::endl;
  s0->print(std::cout); 
  s1->print(std::cout);
  delete s0; 
  delete s1;

	REQUIRE( true );
}
*/
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

