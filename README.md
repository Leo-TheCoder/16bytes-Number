# 16bytes Number
Biểu diiễn và tính toán số học trên máy tính. Đây là đồ án môn học đầu tiên môn Kiến trúc máy tính lớp CQ2018/1.

## Mục lục
- [Nội dung đồ án](#nội-dung-đồ-án)
- [Quy ước chung](#quy-ước-chung)
- [Log](#log)

## Nội dung đồ án
Thiết kế kiểu dữ liệu QInt và Qfloat có độ lớn 16bytes dùng để lưu trữ số tự nhiên và số thực.

### Số tự nhiên lớn - QInt
Thiết kế kiểu dữ liệu và các hàm và toán tử gồm nhập, xuất; các toán tử cơ bản; chuyển đổi qua lại giữa các hệ nhị phân, thập phân và thập lục phân.

### Số chấm động chính xác cao - Qfloat
Thiết kế kiểu dữ liệu và các hàm và toán tử gồm nhập, xuất; chuyển đổi qua lại giữa các hệ nhị phân và thập phân.

## Quy ước chung

### Be a clean coder 

1. Đặt tên biến kiểu camelCase và hàm (function) kiểu CapitalCamelCase, dùng từ tiếng anh dễ hiểu và gọn ghẻ, biến tạm cũng phải đặt là tạm cho cái gì.
2. Đặt tên hằng (constant) dùng kiểu UPPER_SNAKE_CASE.
3. Code rõ ràng không code tắt như:
	- Không có điều kiện rõ ràng trong if: if (SomeVariable) {...}
	- Sử dụng toán tử 3 ngôi: (a>b) ? a : b.
4. Xuống dòng thụt đầu dòng đầy đủ.
5. Không code luôn tuồng, 1 dòng for cũng phải có bracket.
6. Comment code đầy đủ, tránh mơ hồ, không rõ nghĩa.<br />

### Tiêu chí đặt tên biến
  **Tiêu chí 1**: Tên phải thể hiện được đầy đủ ý nghĩa và vai trò của nó. 
Tránh dùng từ nhiều nghĩa, hãy dùng những từ có nghĩa cụ thể. 
Chỉ rõ hành vi thay vì ý định. 
Chèn thêm những thông tin quan trọng vào tên.

  **Tiêu chí 2**: Tên phải rõ ràng và tránh bị hiểu lầm.

## Log

### 04:30PM 29/04/20

**Giải đáp thắc mắc từ giáo viên**
- Xử lý tràn số tính toán giống như cách ngôn ngữ C/C++ xử lý.
- Input vào gây tràn số thì nên có cảnh báo người dùng.
- Giao diện không bắt buộc nhưng bắt buộc phải có phần mềm cho người dùng tương tác tùy ý.
- Phải tự làm thêm một số hàm còn sót trong đề để hoàn thiện đủ chức năng.
- Qfloat cũng phải làm đọc xuất file, định dạng file input giống QInt.

### 09:15PM 28/04/20

**Nội dung họp lần 2**
- Đánh giá chung tình hình đồ án.
- Thảo luận các vấn đề phát sinh.
- Phân chia công việc.

**Tình hình đồ án**
- Gần hoàn tất phần QInt (còn 1 vấn đề nhỏ về quy ước tràn số).
- Qfloat code xong, chưa test

**Vấn đề phát sinh**
- Cách làm việc chung chưa nhất quán.
- QInt phát sinh vấn đề tràn số (Nên tự quy định quy ước riêng hay xử lý giống ngôn ngữ C/C++?).
- Có thể không đủ thời gian để làm giao diện.
- Mâu thuẫn giữa file hướng dẫn đồ án và giáo viên.
  **Giải pháp**: hỏi rõ hơn với giáo viên vào buổi học kế
  
**Kết quả phân việc**
1. Số nguyên
	- Lâm: chia nhỏ, tổ chức lại file cho gọn và dễ nhìn. **Deadline**: 12:00AM 29/04/20
	- Lâm & Duy: thiết kế hàm xuất ra các định dạng nhị phân, thập lục phân. **Deadline**: 12:00PM 30/04/20
	- Kim: thiết kế các hàm nhập xuất file theo định dạng của giáo viên. **Deadline**: 12:00PM 04/05/20
2. Số thực
	- Đức: hoàn thiện xử lý số thực. **Deadline**: 12:00PM 30/04/20
	- Long: Test các hàm cho hoàn chỉnh. **Deadline**: 12:00PM 30/04/20

### 09:17PM 24/04/20

**Nội dung họp lần đầu**
- Trao đổi các hiểu biết về đề tài sẽ làm.
- Phân chia công việc.

**Kết quả phân việc**
1. Số nguyên
	- Lâm: thiết kế hàm nhập (a), xuất (b), chuyển từ thập phân sang nhị phân (c) và ngược lại (d).
	- Duy: thiết kế hàm chuyển từ hệ nhị phân sang thập lục phân (e) và ngược lại (f), toán tử bitwise (i, j).
	- Kim: thiết kế toán tử số học (g) và toán tử so sánh (h).	
2. Số thực
	- Đức: thiết kế hàm nhập (a) và xuất (b)
	- Long: thiết kế hàm chuyển từ hệ nhị phân sang hệ thập phân (c) và ngược lại (d); Thiết kế giao diện phần mềm; Viết báo cáo

  **Deadline**: 08:00AM 28/04/20

### 10:15AM 23/04/20
- Thảo luận cách làm việc.
- Phân công tất cả thành viên tìm hiểu về đề tài.
- Thời gian họp 08:00PM 24/04/20.
