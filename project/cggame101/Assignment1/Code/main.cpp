#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/StdVector>
constexpr double MY_PI = 3.1415926;

EIGEN_DEFINE_STL_VECTOR_SPECIALIZATION(Eigen::Vector4f)

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    std::vector<Eigen::Vector4f,std::allocator<Eigen::Vector4f>> v;
    v.push_back(Eigen::Vector4f());
    v.pop_back();

    std::vector<Eigen::Vector4f,std::allocator<Eigen::Vector4f>> vv;
    vv =v;

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    float rad = rotation_angle/180.0f * MY_PI;
    model<<
    cos(rad),   -sin(rad),  0,  0,
    sin(rad),   cos(rad),   0,  0,
    0,          0,          1,  0,
    0,          0,          0,  1;

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();
    //return projection;

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    float rad = eye_fov / 180.0f * 0.5f* MY_PI;
    float n = -zNear;
    float f = -zFar;
    float t = abs(n) * tan(rad);
    float b = -t;
    float r = t * aspect_ratio;
    float l = -r;

    Eigen::Matrix4f persp2ortho = Eigen::Matrix4f::Identity();
    persp2ortho<<
    n,   0,  0,  0,
    0,   n,   0,  0,
    0,   0,  n+f,  -n*f,
    0,   0,  1,  0;
    

    Eigen::Matrix4f ortho_translate = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f ortho_scale = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f ortho = Eigen::Matrix4f::Identity();
    ortho_translate<<
    1,  0,  0,   -(r+l)/2.0f,
    0,  1,  0,   -(t+b)/2.0f,
    0,  0,  1,   -(n+f)/2.0f,
    0,  0,  0,   1;
    ortho_scale<<
    2.0f/(r-l),  0,   0,   0,
    0,2.0f/(t-b),   0,   0,
    0,  0,2.0f/(n-f),   0,
    0,  0,   0,   1;

    ortho = ortho_scale*ortho_translate;

    projection =  ortho* persp2ortho;
    return projection;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);



    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(60, 1.0f, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(60, 1.0f, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
