import requests
from bs4 import BeautifulSoup

class SimpleSpider:
    def __init__(self, base_url):
        self.base_url = base_url

    def fetch(self, path=""):
        """发送HTTP请求并返回响应内容"""
        url = f"{self.base_url}{path}"
        response = requests.get(url)
        response.raise_for_status()
        return response.text

    def parse(self, html, parser="html.parser"):
        """解析HTML内容并返回BeautifulSoup对象"""
        return BeautifulSoup(html, parser)

    def extract_data(self, soup, selector):
        """根据CSS选择器提取数据"""
        return [element.get_text(strip=True) for element in soup.select(selector)]

    def save_data(self, data, filename):
        """将数据保存到文件"""
        with open(filename, "w", encoding="utf-8") as file:
            for item in data:
                file.write(f"{item}\n")

# 示例用法
if __name__ == "__main__":
    spider = SimpleSpider("https://example.com")
    html = spider.fetch()
    soup = spider.parse(html)
    data = spider.extract_data(soup, "h1")  # 提取所有<h1>标签内容
    spider.save_data(data, "output.txt")
