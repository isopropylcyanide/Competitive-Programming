package com.atlassian.coding;

import com.google.common.collect.Lists;
import lombok.ToString;
import org.apache.commons.collections4.CollectionUtils;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class PresidentialVoteMain {

    @ToString
    static class CandidateVote {

        private final String candidateId;
        private final List<Integer> preferentialVotes;
        private int totalVotes;

        public CandidateVote(String candidateId, int maxPreferentialVotes) {
            this.candidateId = candidateId;
            this.preferentialVotes = new ArrayList<>();
            for (int i = 0; i <= maxPreferentialVotes; i++) {
                preferentialVotes.add(0);
            }
        }

        public void addVote(int preference) {
            totalVotes = totalVotes + 1;
            preferentialVotes.set(preference, preferentialVotes.get(preference) + 1);
        }
    }

    static class CandidateVoteComparator implements Comparator<CandidateVote> {

        @Override
        public int compare(CandidateVote v1, CandidateVote v2) {
            if (v1.preferentialVotes.get(1) > v2.preferentialVotes.get(1)) {
                return -1;

            } else if (v1.preferentialVotes.get(1).equals(v2.preferentialVotes.get(1))) {
                if (v1.preferentialVotes.get(2) >= v2.preferentialVotes.get(2)) {
                    return -1;
                }
                return 1;
            }
            return 1;
        }
    }

    public static String getTopKCandidateWithPreference(List<List<String>> votes, int k) {
        Map<String, CandidateVote> voteCountMap = new HashMap<>();
        CandidateVoteComparator candidateVoteComparator = new CandidateVoteComparator();
        PriorityQueue<CandidateVote> candidateVoteQueue = new PriorityQueue<>(k, candidateVoteComparator);

        final int maxPreferentialVotesPerVoter = 3;
        for (List<String> preferentialVotes : CollectionUtils.emptyIfNull(votes)) {
            for (int preference = 0; preference < preferentialVotes.size(); preference++) {
                String candidate = preferentialVotes.get(preference);
                if (voteCountMap.get(candidate) == null) {
                    voteCountMap.put(candidate, new CandidateVote(candidate, maxPreferentialVotesPerVoter));
                }
                CandidateVote candidateVote = voteCountMap.get(candidate);
                candidateVoteQueue.remove(candidateVote);

                candidateVote.addVote(preference + 1);
                voteCountMap.put(candidate, candidateVote);
                //offer it to the queue
                candidateVoteQueue.add(candidateVote);
            }
        }
        if (candidateVoteQueue.isEmpty()) {
            return null;
        }
        return candidateVoteQueue.poll().candidateId;
//        return MapUtils.emptyIfNull(voteCountMap).values().stream().sorted(candidateVoteComparator).limit(1).map(c -> c.candidateId).findFirst().orElse(null);
    }

    public static String getTopCandidate(List<String> votes) {
        Map<String, Integer> voteCountMap = new HashMap<>();
        String maxVotedCandidate = null;
        int maxVotes = 0;

        for (String vote : CollectionUtils.emptyIfNull(votes)) {
            voteCountMap.putIfAbsent(vote, 0);
            int newVotesForCandidate = voteCountMap.get(vote) + 1;
            voteCountMap.put(vote, newVotesForCandidate);

            if (newVotesForCandidate >= maxVotes) {
                maxVotes = newVotesForCandidate;
                maxVotedCandidate = vote;
            }
        }
        return maxVotedCandidate;
    }

    //upto 3 votes per voter

    /**
     * [
     * [A, B, C]
     * [D, E]
     * ]
     *
     * @param args
     */


    public static void main(String[] args) {

        List<List<String>> votes = Lists.newArrayList(
                Lists.newArrayList("A", "B", "C"),
                Lists.newArrayList("B", "C")
//                Lists.newArrayList("B", "A"),
        );
        String topCandidate = PresidentialVoteMain.getTopKCandidateWithPreference(votes, 1);
        System.out.println("Top: " + topCandidate);

//        List<String> votes = Arrays.asList("A", "B", "A", "C", "D", "B", "A");
//        System.out.println(PresidentialVoteMain.getTopCandidate(votes));
//
//        votes = Arrays.asList("A", "B", "A", "B", "D", "B", "A");
//        System.out.println(PresidentialVoteMain.getTopCandidate(votes));
//
//        System.out.println(PresidentialVoteMain.getTopCandidate(null));

    }
}
