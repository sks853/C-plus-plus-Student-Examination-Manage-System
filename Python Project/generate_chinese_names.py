# -*- coding:utf-8 -*-
# ===============================================
# @Author       HDM
# @Copyright    HDM
# @blogs        https://blog.csdn.net/qq_43634664
# @Version      0.0.1
# @Time         2021/2/9 12:47
# @FileName     generate_chinese_names.py
# @Description  资源参考博客：https://www.jianshu.com/p/94be1c4ebf82 和 https://www.jianshu.com/p/d23e3ac18481
# ===============================================

import random

name = "陈,林,黄,张,李,王,吴,刘,蔡,杨,许,郑,谢,洪,郭,邱,曾,廖,赖,徐,周,叶,苏,庄,吕,江,何,萧,罗,高,周,叶,苏,庄,吕,江,何,萧,罗," \
       "高,潘,简,朱,彭,游,詹,胡,施,沈,余,卢,梁,赵,颜,柯,翁,魏,孙,戴,范,方,宋,邓,杜,傅,侯,曹,薛,丁,卓,马,阮,董,唐,温,蓝,蒋," \
       "石,古,纪,姚,连,冯,欧,程,汤,田,康,姜,汪,白,邹,尤,巫,钟,黎,涂,龚,严,韩,袁,金,童,陆,夏,柳,邵,"

male = "辰,士,以,建,家,致,树,炎,德,行,时,泰,盛,雄,琛,钧,冠,策,铭,腾,伟,刚,勇,毅,俊,峰,强,军,平,保,东,文,辉,力,明,永,健,世,广," \
       "志,义,兴,良,海,山,仁,波,宁,贵,福,生,龙,元,全,国,胜,学,祥,才,发,成,康,星,光,天,达,安,岩,中,茂,武,新,利,清,飞,彬,富,顺," \
       "信,子,杰,楠,榕,风,航,弘,鼎"

female = "嘉,琼,桂,娣,叶,璧,璐,娅,琦,晶,妍,茜,秋,珊,莎,锦,黛,青,倩,婷,姣,婉,娴,瑾,颖,露,瑶,怡,婵,雁,蓓,纨,仪,荷,丹,蓉,眉,君," \
         "琴,蕊,薇,菁,梦,岚,苑,婕,馨,瑗,琰,韵,融,园,艺,咏,卿,聪,澜,纯,毓,悦,昭,冰,爽,琬,茗,羽,希,宁,欣,飘,育,滢,馥,筠,柔,竹," \
         "霭,凝,晓,欢,霄,枫,芸,菲,寒,伊,亚,宜,可,姬,舒,影,荔,枝,思,丽,秀,娟,英,华,慧,巧,美,娜,静,淑,惠,珠,翠,雅,芝,玉,萍,红," \
         "娥,玲,芬,芳,燕,彩,春,菊,勤,珍,贞,莉,兰,凤,洁,梅,琳,素,云,莲,真,环,雪,荣,爱,妹,霞,香,月,莺,媛,艳,瑞,凡,佳"

ls_name_last = [
    '赵', '钱', '孙', '李', '周', '吴', '郑', '王', '冯', '陈', '褚', '卫', '蒋', '沈', '韩', '杨', '朱', '秦', '尤', '许',
    '何', '吕', '施', '张', '孔', '曹', '严', '华', '金', '魏', '陶', '姜', '戚', '谢', '邹', '喻', '柏', '水', '窦', '章',
    '云', '苏', '潘', '葛', '奚', '范', '彭', '郎', '鲁', '韦', '昌', '马', '苗', '凤', '花', '方', '俞', '任', '袁', '柳',
    '酆', '鲍', '史', '唐', '费', '廉', '岑', '薛', '雷', '贺', '倪', '汤', '滕', '殷', '罗', '毕', '郝', '邬', '安', '常',
    '乐', '于', '时', '傅', '皮', '卞', '齐', '康', '伍', '余', '元', '卜', '顾', '孟', '平', '黄', '和', '穆', '萧', '尹',
    '姚', '邵', '堪', '汪', '祁', '毛', '禹', '狄', '米', '贝', '明', '臧', '计', '伏', '成', '戴', '谈', '宋', '茅', '庞',
    '熊', '纪', '舒', '屈', '项', '祝', '董', '梁'
]
ls_name_first_male = male.split(',')
ls_name_first_female = female.split(',')


def generate_name(gender):
    name_length = random.choice((2, 3))
    if gender == 0:
        if name_length == 2:
            return random.choice(ls_name_last) + random.choice(ls_name_first_female)
        if name_length == 3:
            return random.choice(ls_name_last) + random.choice(ls_name_first_female) + \
                   random.choice(ls_name_first_female)
    if gender == 1:
        if name_length == 2:
            return random.choice(ls_name_last) + random.choice(ls_name_first_male)
        if name_length == 3:
            return random.choice(ls_name_last) + random.choice(ls_name_first_male) + \
                   random.choice(ls_name_first_male)

    return None


if __name__ == '__main__':
    """ main """
    ls = []
    for i in range(eval(input())):
        # genders = random.choice((0, 1))
        genders = 0
        ls.append(generate_name(gender=genders))
    print(ls)
