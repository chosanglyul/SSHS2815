import numpy as np
import matplotlib.pyplot as plt
import random
from math import pi, sin, cos

def check(radius, point):
    return (radius/2)**2 > (point[0]**2+point[1]**2)

def get1(radius):
    x = 1
    y = 1
    while(x**2+y**2 > 1):
        x = random.random()*2-1
        y = random.random()*2-1
    return [x*radius, y*radius]

def get2(radius):
    dist = random.random()*radius
    theta = random.random()*2*pi
    return [dist*cos(theta), dist*sin(theta)]

def get3(radius):
    phi = random.random()*2*pi
    theta = random.random()*pi
    return [radius*cos(theta)*cos(theta+phi), radius*cos(theta)*sin(theta+phi)]

def draw(arr, radius, index, trys, save):
    fig, ax = plt.subplots(figsize=(10, 10))
    circle = plt.Circle((0, 0), radius, fill=False, color='black', lw=0.2)
    ax.set_xlim((-radius, radius))
    ax.set_ylim((-radius, radius))
    ax.add_artist(circle)
    ax.scatter(arr[0], arr[1], s=0.001)
    if save: fig.savefig('res'+str(index+1)+'.png')
    else: plt.show()

if __name__ == '__main__':
    radius = 1.00
    trytimes = 1000000
    get = [get1, get2, get3]
    for i in range(3):
        res = np.array([get[i](radius) for j in range(trytimes)])
        draw(res.T, radius, i, trytimes, True)
        compared = np.array([check(radius, point) for point in res])
        print(i, np.count_nonzero(compared))