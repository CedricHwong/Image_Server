// 实现一个数据库接口测试程序, 用来验证前面的数据库接口是否正确
#include <iostream>
#include "db.hpp"
#include "json/json.h"

MYSQL *MySQLInit();

void MySQLRelease(MYSQL *pMysql);

using namespace std;
void TestImageTable() {
    bool ret = false;
    // 更友好的格式化显示 Json
    Json::StyledWriter writer;
    MYSQL* mysql = MySQLInit();
    Json::Value image;
    image["name"] = "滑稽.jpg";
    image["size"] = 16 * 1024;
    image["upload_time"] = "2019/01/01";
    image["md5"] = "987654321";
    image["content_type"] = "image/jpg";
    image["path"] = "./滑稽.jpg";
    std::cout << "==============测试插入=====================" << std::endl;
    picdb::ImageTable image_table(mysql);
    ret = image_table.Insert(image);
    std::cout << "Insert: " << ret << std::endl;
    std::cout << "==============测试查找=====================" << std::endl;
    Json::Value images;
    ret = image_table.SelectAll(&images);
    std::cout << "SelectAll: " << ret << std::endl
              << writer.write(images) << std::endl;
    Json::Value image_out;
    ret = image_table.SelectOne(1, &image_out);
    std::cout << "SelectOne: " << ret << std::endl
              << writer.write(image_out) << std::endl;
    std::cout << "==============测试删除=====================" << std::endl;
    int image_id = 2;
    ret = image_table.Delete(image_id);
    std::cout << "Delete: " << ret << std::endl;
    MySQLRelease(mysql);
}

void MySQLRelease(MYSQL *pMysql) {

}

MYSQL *MySQLInit() {
    return nullptr;
}

int main() {
    TestImageTable();
    return 0;
}

//
// Created by Cedric Hwong on 3/6/20.
//

