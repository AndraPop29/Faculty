from f_functii_secundare import *
def test_adauga():
    l=[10,20,30,40,50,60,70,80,90]
    assert.adauga(l,100)==[10,20,30,40,50,60,70,80,90,100]
    assert.adauga(l,12)==[10,20,30,40,50,60,70,80,90,12]
    assert.adauga(l,22)==[10,20,30,40,50,60,70,80,90,22]
    assert.adauga(l,0)==[10,20,30,40,50,60,70,80,90,0]
test_adauga()
def test_insert():
    l=[10,20,30,40,50,60,70,80,90,100]
    assert.insert(l,0,100)==[100,10,20,30,40,50,60,70,80,90,100]
    assert.insert(l,1,100)==[10,100,20,30,40,50,60,70,80,90,100]
    assert.insert(l,2,100)==[10,20,100,30,40,50,60,70,80,90,100]
    assert.insert(l,3,100)==[10,20,30,100,40,50,60,70,80,90,100]
test_insert()
def test_sterge():
    l=[10,20,30,40,50,60,70,80,90]
    assert.sterge(l,0)==[20,30,40,50,60,70,80,90,100]
    assert.sterge(l,1)==[10,30,40,50,60,70,80,90,100]
    assert.sterge(l,3)==[10,20,30,50,60,70,80,90,100]
    assert.sterge(l,5)==[10,20,30,40,50,70,80,90,100]
test_sterge()
def test_sterge_secventa():
    l=[10,20,30,40,50,60,70,80,90]
    assert.adauga(l,0,1)==[30,40,50,60,70,80,90,100]
    assert.adauga(l,0,2)==[40,50,60,70,80,90,100]
    assert.adauga(l,0,3)==[50,60,70,80,90,100]
    assert.adauga(l,1,5)==[10,70,80,90,100]
test_sterge_secventa()
def test_inlocuire():
    l=[10,20,30,40,50,60,70,80,90]
    assert.adauga(l,0,100)==[100,20,30,40,50,60,70,80,90,100]
    assert.adauga(l,1,100)==[10,100,30,40,50,60,70,80,90,100]
    assert.adauga(l,3,100)==[10,20,100,40,50,60,70,80,90,100]
    assert.adauga(l,0,20)==[20,20,30,40,50,60,70,80,90,100]
test_inlocuire()
def test_media_aritmetica():
    l=[10,20,30,40,50,60,70,80,90]
   assert.adauga(l,0,2)==20
   assert.adauga(l,1,3)==30
   assert.adauga(l,2,4)==40
   assert.adauga(l,0,4)==30
test_media_aritmetica()
def test_minim():
    l=[10,20,30,40,50,60,70,80,90]
    assert.adauga(l,0,2)==10
    assert.adauga(l,0,3)==10
    assert.adauga(l,1,4)==20
    assert.adauga(l,5,7)==60
test_minim()
def test_filtrare_10():
    l=[11,22,30,44,56,60,70,80,90]
    assert.adauga(l)==[30,60,70,80,90]
test_filtrare_10()
def test_filtrare_70():
    l=[10,20,30,40,50,60,70,80,90]
    assert.adauga(l)==[80,90,100]
test_filtrare_70()