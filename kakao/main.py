import requests
import json

base_url = "https://pegkq2svv6.execute-api.ap-northeast-2.amazonaws.com/prod/users"


#Start api

headers = {
    'X-Auth-Token': '79665a8fd53c9d77ac74981fe915ce4b',
    'Content-Type': 'application/json',
}
data = '{ "problem": 2 }'
response = requests.post(base_url+'/start', headers=headers, data=data)
au = response.json()
print(au['auth_key'])
N = 25
T = 5
edge = 5

if au['problem'] == 2:
    N = 3600
    T = 10
    edge = 60
# for key, value in au.items():
#     print(key, ":", value)
#Locations api

headers = {
    'Authorization': au['auth_key'],
    'Content-Type': 'application/json',
}
# r = requests.get(base_url+'/locations', headers=headers)
# print("status code: ", r.status_code)
# #get
#
# loc = (r.json())['locations']
# locations = dict((x['id'], x['located_bikes_count']) for x in loc)
# print(locations)
# for k, v in locations.items():
#     print(k , ": " , v)
#
# print("called json locations")
# for l in locations['locations']:
#     print(l['id'], l['located_bikes_count'])
#


#Trucks api
# r = requests.get(base_url+'/trucks', headers=headers)
# tru = (r.json())['trucks']
# trucks = dict((x['id'], {'loc': x['location_id'], 'cnt': x['loaded_bikes_count']}) for x in tru)
# print(trucks)

r = requests.get(base_url + '/locations', headers=headers)
# print("status code: ", r.status_code)
loc = (r.json())['locations']
locations = dict((x['id'], x['located_bikes_count']) for x in loc)
print(locations)
r = requests.get(base_url + '/trucks', headers=headers)
tru = (r.json())['trucks']
trucks = dict((x['id'], {'loc': x['location_id'], 'cnt': x['loaded_bikes_count']}) for x in tru)

# command str 반환 함수
def get_command(id, command, res):
    res = res + '{ "truck_id": ' + str(id)
    res = res + ', "command": ' + str(command) + '}'
    return res

def truck_drive(_i, _j): # i to j, 상하차는 loop에서 하는걸로
    res = []
    if _i < _j:
        while _i//edge < _j//edge:
            _i += edge
            res.append(2)
        while _i < _j:
            res.append(1)
            _i += 1
        while _i > _j:
            res.append(3)
            _i -= 1
    else:
        while _i//edge > _j//edge:
            res.append(4)
            _i -= edge
        while _i < _j:
            res.append(1)
            _i += 1
        while _i > _j:
            res.append(3)
            _i -= 1
    return res


def get_dist(_i, _j):
    dist = 0
    if _i < _j:
        while _i//edge < _j//edge:
            _i += edge
            dist += 1
        while _i < _j:
            _i += 1
            dist += 1
        while _i > _j:
            _i -= 1
            dist += 1
    else:
        while _i//edge > _j//edge:
            _i -= edge
            dist += 1
        while _i < _j:
            _i += 1
            dist += 1
        while _i > _j:
            _i -= 1
            dist += 1
    return dist

def find_truck(_i, _trucks, _moved):
    minid = -1
    mindist = 100
    for id in range(0, T):
        if _moved[id] == 1: continue
        tdist = get_dist(_trucks[id]['loc'], _i)
        if tdist < mindist:
            minid = id
            mindist = tdist
    return minid

#Simulate
command = []
for _ in range(0, 720):
    print(_)
    r = requests.get(base_url + '/locations', headers=headers)
    # print("status code: ", r.status_code)
    loc = (r.json())['locations']
    locations = dict((x['id'], x['located_bikes_count']) for x in loc)
    # print(locations)
    r = requests.get(base_url + '/trucks', headers=headers)
    tru = (r.json())['trucks']
    trucks = dict((x['id'], {'loc': x['location_id'], 'cnt': x['loaded_bikes_count']}) for x in tru)

    flag = False

    moved = [0 for __ in range(T)]
    data = '{ "commands": ['
    for i in range(0, N):
        if locations[i] <= 2:
            f2 = False
            tcommand = list()
            for k in range(0, T):
                if (trucks[k]['cnt']) > 0:
                    # print("cnt", i)
                    if flag:
                        data += ', '
                    else:
                        flag = True
                    tcommand.extend(truck_drive(trucks[k]['loc'], i))
                    tcommand.append(6)
                    trucks[k]['cnt'] -= 1
                    moved[k] = 1
                    f2 = True
                    data = get_command(k, tcommand, data)
                    break
            if f2:
                continue

            # 바이크 있는 트럭 없음
            for j in range(0, N):
                if locations[j] > locations[i] + 1: # truck to j, j to i
                    truck_to_move = find_truck(i, trucks, moved)
                    if truck_to_move == -1:
                        continue
                    tcommand.extend(truck_drive(trucks[truck_to_move]['loc'], j))
                    tcommand.append(5)
                    locations[j] -= 1
                    # print(locations[j])
                    tcommand.extend(truck_drive(j, i))
                    tcommand.append(6)
                    trucks[truck_to_move]['loc'] = i
                    moved[truck_to_move] = 1
                    if flag:
                        data += ', '
                    else:
                        flag = True
                    data = get_command(truck_to_move, tcommand, data)
                    break

    # print(trucks)
    # 중간 추가면 + ', '

    data = data + '] }'
    # simulate api
    # print(data)
    r = requests.put(base_url + '/simulate', headers=headers, data=data)
    resp = r.json()
    print(r.status_code)
    for key, val in resp.items():
       print(key,": ", val)

# score api
r = requests.get(base_url + '/score', headers=headers)
print(r.json())