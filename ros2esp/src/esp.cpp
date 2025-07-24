// 標準
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

// ROS
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"

class PS4_Listener : public rclcpp::Node {

    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg) {
    std_msgs::msg::Int16MultiArray output;
// int16_t型の配列を用意
int16_t data[19] = {0};
//0〜３モタドラ　４〜７サーボ　８〜１５ＳＶ　１６〜１９enc


// コントローラーの入力を取得、使わない入力はコメントアウト推奨
        //  float LS_X = -1 * msg->axes[0];
        //  float LS_Y = msg->axes[1];
        //  float RS_X = -1 * msg->axes[3];
        //  float RS_Y = msg->axes[4];

        // bool CROSS = msg->buttons[0];
        bool CIRCLE = msg->buttons[1];
        // bool TRIANGLE = msg->buttons[2];
        // bool SQUARE = msg->buttons[3];

        // bool LEFT = msg->axes[6] == 1.0;
        // bool RIGHT = msg->axes[6] == -1.0;
        // bool UP = msg->axes[7] == 1.0;
        // bool DOWN = msg->axes[7] == -1.0;

        // bool L1 = msg->buttons[4];
        //  bool R1 = msg->buttons[5];

          float LS_X = -1 * msg->axes[0];
          float LS_Y = msg->axes[1];
          float RS_X = -1 * msg->axes[3];
          float RS_Y = msg->axes[4];


        float L2 = (-1 * msg->axes[2] + 1) / 2;
        float R2 = (-1 * msg->axes[5] + 1) / 2;


data[4] = R2 * 255;
data[5] = L2 * 255;

data[0] = LS_Y
date[1] = RS_X


       
   // publish 用にコピー
    for (int i = 0; i < 6; ++i) {
        output.data.push_back(data[i]);
    }

    publisher->publish(output);
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("simple_motor_pub");

    publisher = node->create_publisher<std_msgs::msg::Int16MultiArray>("motordata", 10);

    auto sub = node->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 10, joy_callback);

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

