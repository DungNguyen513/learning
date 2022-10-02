use master

if exists (select * from sys.databases where name = 'QLBANHANG')
	drop database QLBANHANG
go

-- Tạo database QLBANHANG
create database QLBANHANG
go
use QLBANHANG

-- Tạo table KHACHHANG
create table KHACHHANG (
MAKH		varchar(5)		primary key,
TENKH		nvarchar(30)	not null,
DIACHI		nvarchar(50),
DT			varchar(11)		check (len(DT) between 8 and 11),
EMAIL		varchar(30)
)

-- Tạo table VATTU
create table VATTU (
MAVT		varchar(5)		primary key,
TENVT		nvarchar(30)	not null,
DVT			nvarchar(20),
GIAMUA		money			check (GIAMUA > 0),
SLTON		int				check (SLTON >= 0)
)

-- Tạo table HOADON
create table HOADON (
MAHD		varchar(10)		primary key,
NGAY		date			check (NGAY < getdate()),
MAKH		varchar(5)		foreign key references KHACHHANG(MAKH),
TONGTG		float
)

-- Tạo table CTHD
create table CTHD (
MAHD		varchar(10)		foreign key references HOADON(MAHD),
MAVT		varchar(5)		foreign key references VATTU(MAVT),
SL			int				check (SL > 0),
KHUYENMAI	float,
GIABAN		float
)

-- Chèn data vào table VATTU
insert into VATTU values
('VT01', N'Xi măng', 'Bao', 50000, 5000),
('VT02', N'Cát', N'Khối', 45000, 50000),
('VT03', N'Gạch', N'Viên', 120, 800000),
('VT04', N'Gạch thẻ', N'Viên', 110, 800000),
('VT05', N'Đá lớn', N'Khối', 25000, 100000),
('VT06', N'Đá nhỏ', N'Khối', 33000, 100000),
('VT07', N'Lam gió', N'Cái', 15000, 50000)

-- Chèn data vào table KHACHHANG
insert into KHACHHANG values
('KH01', N'Nguyễn Thị Bé', N'Tân Bình', '038457895', 'bnt@yahoo.com'),
('KH02', N'Lê Hoàng Nam', N'Bình Chánh', '039878987', 'namlehoang@gmail.com'),
('KH03', N'Trần Thị Chiêu', N'Tân Bình', '038457895', null),
('KH04', N'Mai Thị Quế Anh', N'Bình Chánh', null, null),
('KH05', N'Lê Văn Sáng', N'Quận 10', null, 'sanglv@hcm.vnn.vn'),
('KH06', N'Trần Hoàng', N'Tân Bình', '038457897', null)

-- Chèn data vào table HOADON
insert into HOADON values
('HD001', '2010/05/12', 'KH01', null),
('HD002', '2010/05/25', 'KH02', null),
('HD003', '2010/05/25', 'KH01', null),
('HD004', '2010/05/25', 'KH04', null),
('HD005', '2010/05/26', 'KH04', null),
('HD006', '2010/06/02', 'KH03', null),
('HD007', '2010/06/22', 'KH04', null),
('HD008', '2010/06/25', 'KH03', null),
('HD009', '2010/08/15', 'KH04', null),
('HD010', '2010/09/30', 'KH01', null)

-- Chèn data vào table CTHD
insert into CTHD values
('HD001', 'VT01', 5, null, 52000),
('HD001', 'VT05', 10, null, 30000),
('HD002', 'VT03', 10000, null, 150),
('HD003', 'VT02', 20, null, 55000),
('HD004', 'VT03', 50000, null, 150),
('HD004', 'VT04', 20000, null, 120),
('HD005', 'VT05', 10, null, 30000),
('HD005', 'VT06', 15, null, 35000),
('HD005', 'VT07', 20, null, 17000),
('HD006', 'VT04', 10000, null, 120),
('HD007', 'VT04', 20000, null, 125),
('HD008', 'VT01', 100, null, 55000),
('HD008', 'VT02', 20, null, 47000),
('HD009', 'VT02', 25, null, 48000),
('HD010', 'VT01', 25, null, 57000)



----------------------- TRUY VẤN -----------------------
-- 1. Hiển thị danh sách các khách hàng có địa chỉ là "Tân Bình" gồm mã khách 
--    hàng, tên khách hàng, địa chỉ, điện thoại, và địa chỉ E-mail.
select * from KHACHHANG
where DIACHI = N'Tân Bình'

-- 2. Hiển thị danh sách các khách hàng gồm các thông tin mã khách hàng, tên 
--    khách hàng, địa chỉ và địa chỉ E-mail của những khách hàng chưa có số 
--    điện thoại.
select MAKH, TENKH, DIACHI, EMAIL from KHACHHANG
where DT is null

-- 3. Hiển thị danh sách các khách hàng chưa có số điện thoại và cũng chưa có 
--    địa chỉ Email gồm mã khách hàng, tên khách hàng, địa chỉ.
select MAKH, TENKH, DIACHI from KHACHHANG
where DT is null and EMAIL is null

-- 4. Hiển thị danh sách các khách hàng đã có số điện thoại và địa chỉ E-mail 
--    gồm mã khách hàng, tên khách hàng, địa chỉ, điện thoại, và địa chỉ Email.
select * from KHACHHANG
where DT is not null and EMAIL is not null

-- 5. Hiển thị danh sách các vật tư có đơn vị tính là "Cái" gồm mã vật tư, tên 
--    vật tư và giá mua.
select MAVT, TENVT, GIAMUA from VATTU
where DVT = N'Cái'

-- 6. Hiển thị danh sách các vật tư gồm mã vật tư, tên vật tư, đơn vị tính và 
--    giá mua mà có giá mua trên 25000.
select MAVT, TENVT, DVT, GIAMUA from VATTU
where GIAMUA > 25000

-- 7. Hiển thị danh sách các vật tư là "Gạch" (bao gồm các loại gạch) gồm mã 
--    vật tư, tên vật tư, đơn vị tính và giá mua.
select MAVT, TENVT, DVT, GIAMUA from VATTU
where TENVT like N'Gạch%'

-- 8. Hiển thị danh sách các vật tư gồm mã vật tư, tên vật tư, đơn vị tính và 
--    giá mua mà có giá mua nằm trong khoảng từ 20000 đến 40000.
select MAVT, TENVT, DVT, GIAMUA from VATTU
where GIAMUA between 20000 and 40000

-- 9. Lấy ra các thông tin gồm Mã hóa đơn, ngày lập hóa đơn, tên khách hàng, 
--    địa chỉ khách hàng và số điện thoại.
-- https://www.mssqltips.com/sqlservertip/1145/date-and-time-conversions-using-sql-server/
select hd.MAHD, convert(varchar, hd.NGAY, 103) as NGAY, kh.TENKH, kh.DIACHI, kh.DT
from HOADON hd, KHACHHANG kh
where kh.MAKH = hd.MAKH

-- 10. Lấy ra các thông tin gồm Mã hóa đơn, tên khách hàng, địa chỉ khách hàng 
--     và số điện thoại của ngày 25/5/2010.
select hd.MAHD, kh.TENKH, kh.DIACHI, kh.DT
from HOADON hd, KHACHHANG kh
where kh.MAKH = hd.MAKH and hd.NGAY = '2010/5/25'

-- 11. Lấy ra các thông tin gồm Mã hóa đơn, ngày lập hóa đơn, tên khách hàng, 
--     địa chỉ khách hàng và số điện thoại của những hóa đơn trong tháng 6/2010.
-- https://www.mssqltips.com/sqlservertip/1145/date-and-time-conversions-using-sql-server/
select hd.MAHD, convert(varchar, hd.NGAY, 103) as NGAY, kh.TENKH, kh.DIACHI, kh.DT
from HOADON hd, KHACHHANG kh
where kh.MAKH = hd.MAKH and month(hd.NGAY) = '6' and year(hd.NGAY) = '2010'

-- 12. Lấy ra danh sách những khách hàng (tên khách hàng, địa chỉ, số điện 
--     thoại) đã mua hàng trong tháng 6/2010.
select kh.TENKH, kh.DIACHI, kh.DT
from HOADON hd, KHACHHANG kh
where kh.MAKH = hd.MAKH and month(hd.NGAY) = '6' and year(hd.NGAY) = '2010'

-- 13. Lấy ra danh sách những khách hàng không mua hàng trong tháng 6/2010 
--     gồm các thông tin tên khách hàng, địa chỉ, số điện thoại.
select TENKH, DIACHI, DT from KHACHHANG
where MAKH not in (
				   select MAKH from HOADON
				   where month(NGAY) = '6' and year(NGAY) = '2010'
				  )

-- 14. Lấy ra các chi tiết hóa đơn gồm các thông tin mã hóa đơn, mã vật tư, tên 
--     vật tư, đơn vị tính, giá bán, giá mua, số lượng, trị giá mua (giá mua * số 
--     lượng), trị giá bán (giá bán * số lượng).
select ct.MAHD, ct.MAVT, vt.TENVT, vt.DVT, ct.GIABAN, vt.GIAMUA, ct.SL,
	   (vt.GIAMUA * ct.SL) as TGMUA, (ct.GIABAN * ct.SL) as TGBAN
from CTHD ct, VATTU vt
where ct.MAVT = vt.MAVT

-- 15. Lấy ra các chi tiết hóa đơn gồm các thông tin mã hóa đơn, mã vật tư, tên 
--     vật tư, đơn vị tính, giá bán, giá mua, số lượng, trị giá mua (giá mua * số 
--     lượng), trị giá bán (giá bán * số lượng) mà có giá bán lớn hơn hoặc bằng 
--     giá mua.
select ct.MAHD, ct.MAVT, vt.TENVT, vt.DVT, ct.GIABAN, vt.GIAMUA, ct.SL,
	   (vt.GIAMUA * ct.SL) as TGMUA, (ct.GIABAN * ct.SL) as TGBAN
from CTHD ct, VATTU vt
where ct.MAVT = vt.MAVT and ct.GIABAN >= vt.GIAMUA

-- 16. Lấy ra các thông tin gồm mã hóa đơn, mã vật tư, tên vật tư, đơn vị tính, 
--     giá bán, giá mua, số lượng, trị giá mua (giá mua * số lượng), trị giá bán 
--     (giá bán * số lượng) và cột khuyến mãi với khuyến mãi 10% cho những 
--     mặt hàng bán trong một hóa đơn lớn hơn 100
select ct.MAHD, vt.MAVT, vt.TENVT, vt.DVT, ct.GIABAN, vt.GIAMUA, ct.SL,
	   (vt.GIAMUA * ct.SL) as TGMUA, (ct.GIABAN * ct.SL) as TGBAN,
	   'KHUYENMAI' = case when ct.SL > 100 then 0.1 else 0 end
from VATTU vt, CTHD ct
where ct.MAVT = vt.MAVT

-- 17. Tìm ra những mặt hàng chưa bán được.
select * from VATTU
where MAVT not in (select MAVT from CTHD)

-- 18. Tạo bảng tổng hợp gồm các thông tin: mã hóa đơn, ngày hóa đơn, tên 
--     khách hàng, địa chỉ, số điện thoại, tên vật tư, đơn vị tính, giá mua, giá 
--     bán, số lượng, trị giá mua, trị giá bán.
-- https://www.mssqltips.com/sqlservertip/1145/date-and-time-conversions-using-sql-server/
select ct.MAHD, convert(varchar, hd.NGAY, 103) as NGAY, kh.TENKH, kh.DIACHI,
	   kh.DT, vt.TENVT, vt.DVT, vt.GIAMUA, ct.GIABAN, ct.SL,
	   (vt.GIAMUA * ct.SL) as TGMUA, (ct.GIABAN * ct.SL) as TGBAN
from VATTU vt, CTHD ct, KHACHHANG kh, HOADON hd
where ct.MAVT = vt.MAVT and hd.MAKH = kh.MAKH and hd.MAHD = ct.MAHD

-- 19. Tạo bảng tổng hợp tháng 5/2010 gồm các thông tin: mã hóa đơn, ngày 
--     hóa đơn, tên khách hàng, địa chỉ, số điện thoại, tên vật tư, đơn vị tính, 
--     giá mua, giá bán, số lượng, trị giá mua, trị giá bán.
select ct.MAHD, convert(varchar, hd.NGAY, 103) as NGAY, kh.TENKH, kh.DIACHI,
	   kh.DT, vt.TENVT, vt.DVT, vt.GIAMUA, ct.GIABAN, ct.SL,
	   (vt.GIAMUA * ct.SL) as TGMUA, (ct.GIABAN * ct.SL) as TGBAN
from VATTU vt, CTHD ct, KHACHHANG kh, HOADON hd
where ct.MAVT = vt.MAVT and hd.MAKH = kh.MAKH and hd.MAHD = ct.MAHD
	  and month(hd.NGAY) = '5' and year(hd.NGAY) = '2010'

-- 20. Tạo bảng tổng hợp quý 1 – 2010 gồm các thông tin: mã hóa đơn, ngày 
--     hóa đơn, tên khách hàng, địa chỉ, số điện thoại, tên vật tư, đơn vị tính, 
--     giá mua, giá bán, số lượng, trị giá mua, trị giá bán.
select ct.MAHD, convert(varchar, hd.NGAY, 103) as NGAY, kh.TENKH, kh.DIACHI,
	   kh.DT, vt.TENVT, vt.DVT, vt.GIAMUA, ct.GIABAN, ct.SL,
	   (vt.GIAMUA * ct.SL) as TGMUA, (ct.GIABAN * ct.SL) as TGBAN
from VATTU vt, CTHD ct, KHACHHANG kh, HOADON hd
where ct.MAVT = vt.MAVT and hd.MAKH = kh.MAKH and hd.MAHD = ct.MAHD
	  and (month(hd.NGAY) between 1 and 3)  and year(hd.NGAY) = '2010'

-- 21. Lấy ra danh sách các hóa đơn gồm các thông tin: Số hóa đơn, ngày, tên 
--	   khách hàng, địa chỉ khách hàng, tổng trị giá của hóa đơn.
select ct.MAHD, convert(varchar, hd.NGAY, 103) as NGAY, kh.TENKH, kh.DIACHI,
	   hd.TONGTG
from VATTU vt, CTHD ct, HOADON hd, KHACHHANG kh
where ct.MAVT = vt.MAVT and ct.MAHD = hd.MAHD and hd.MAKH = kh.MAKH

-- 22. Lấy ra hóa đơn có tổng trị giá lớn nhất gồm các thông tin: Số hóa đơn, 
--	   ngày, tên khách hàng, địa chỉ khách hàng, tổng trị giá của hóa đơn.
select ct.MAHD, hd.NGAY, kh.TENKH, kh.DIACHI, sum(ct.GIABAN * ct.SL) TONGTG
from CTHD ct, HOADON hd, KHACHHANG kh
where ct.MAHD = hd.MAHD and hd.MAKH = kh.MAKH
group by ct.MAHD, hd.NGAY, kh.TENKH, kh.DIACHI
having sum(ct.GIABAN * ct.SL) >= all(
									 select sum(ct.GIABAN * ct.SL)
									 from CTHD ct, HOADON hd, KHACHHANG kh
									 where ct.MAHD = hd.MAHD and hd.MAKH = kh.MAKH
									 group by ct.MAHD, hd.NGAY, kh.TENKH, kh.DIACHI
								    )

-- 23. Lấy ra hóa đơn có tổng trị giá lớn nhất trong tháng 5/2010 gồm các thông 
--	   tin: Số hóa đơn, ngày, tên khách hàng, địa chỉ khách hàng, tổng trị giá 
--	   của hóa đơn.
select ct.MAHD, hd.NGAY, kh.TENKH, kh.DIACHI, sum(ct.GIABAN * ct.SL) TONGTG
from CTHD ct, HOADON hd, KHACHHANG kh
where ct.MAHD = hd.MAHD and hd.MAKH = kh.MAKH
	  and month(hd.NGAY) = '5' and year(hd.NGAY) = '2010'
group by ct.MAHD, hd.NGAY, kh.TENKH, kh.DIACHI
having sum(ct.GIABAN * ct.SL) >= all(
									 select sum(ct.GIABAN * ct.SL)
									 from CTHD ct, HOADON hd, KHACHHANG kh
									 where ct.MAHD = hd.MAHD and hd.MAKH = kh.MAKH
									 group by ct.MAHD, hd.NGAY, kh.TENKH, kh.DIACHI
								    )

-- 24. Đếm xem mỗi khách hàng có bao nhiêu hóa đơn.
select kh.MAKH, kh.TENKH, count(*) as SLHD
from KHACHHANG kh, HOADON hd
where kh.MAKH = hd.MAKH
group by kh.MAKH, kh.TENKH

-- 25. Đếm xem mỗi khách hàng, mỗi tháng có bao nhiêu hóa đơn.


-- 26. Lấy ra các thông tin của khách hàng có số lượng hóa đơn mua hàng nhiều 
--	   nhất.
select kh.MAKH, kh.TENKH, count(*) as SLHD
from KHACHHANG kh, HOADON hd
where kh.MAKH = hd.MAKH
group by kh.MAKH, kh.TENKH
having count(*) >= all (
						select count(*)
						from KHACHHANG kh, HOADON hd
						where kh.MAKH = hd.MAKH
						group by kh.MAKH, kh.TENKH
					   )

-- 27. Lấy ra các thông tin của khách hàng có số lượng hàng mua nhiều nhất.
select kh.MAKH, kh.TENKH, sum(ct.SL) as SLH
from KHACHHANG kh, HOADON hd, CTHD ct
where hd.MAHD = ct.MAHD and kh.MAKH = hd.MAKH
group by kh.MAKH, kh.TENKH
having sum(ct.SL) >= all (
						  select sum(ct.SL)
						  from KHACHHANG kh, HOADON hd, CTHD ct
						  where hd.MAHD = ct.MAHD and kh.MAKH = hd.MAKH
						  group by kh.MAKH, kh.TENKH
					     )

-- 28. Lấy ra các thông tin về các mặt hàng mà được bán trong nhiều hóa đơn 
--	   nhất.
select ct.MAHD, vt.TENVT, count(*) as SLB
from CTHD ct, VATTU vt
where ct.MAVT = vt.MAVT
group by ct.MAHD, vt.TENVT
having count(*) >= all(
					   select count(*)
					   from CTHD ct, VATTU vt
					   where ct.MAVT = vt.MAVT
					   group by ct.MAHD, vt.TENVT
					  )

-- 29. Lấy ra các thông tin về các mặt hàng mà được bán nhiều nhất.
select ct.MAVT, vt.TENVT, count(*) as SL
from CTHD ct, VATTU vt
where vt.MAVT = ct.MAVT
group by ct.MAVT, vt.TENVT
having count(*) >= all(
					   select count(*)
					   from CTHD ct, VATTU vt
					   where vt.MAVT = ct.MAVT
					   group by ct.MAVT, vt.TENVT
					  )

-- 30. Lấy ra danh sách tất cả các khách hàng gồm Mã khách hàng, tên khách 
--	   hàng, địa chỉ, số lượng hóa đơn đã mua (nếu khách hàng đó chưa mua 
--	   hàng thì cột số lượng hóa đơn để trống)
select kh.MAKH, kh.TENKH, kh.DIACHI,
	case when (not exists (select MAKH from HOADON)) then 0
		else (
			  select sum(ct.SL)
			  from HOADON hd, CTHD ct
			  where ct.MAHD = hd.MAHD and hd.MAKH = kh.MAKH
			  group by hd.MAKH
			 ) end as SLHD
from KHACHHANG kh
